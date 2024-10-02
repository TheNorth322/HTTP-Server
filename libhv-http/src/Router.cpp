#include "Router.hpp"
#include "../../nlohmann-json/json.hpp"
#include "entity/User.hpp"
#include "utility/Base64Encoder.hpp"
#include "utility/UUIDv4Generator.hpp"
#include <optional>
#include <variant>

const int auth_header_prefix_end = 6;

std::optional<route::Router::credentials_t> route::Router::parse_auth_header(const std::string &header) {
    if (header.size() < auth_header_prefix_end) {
        return {};
    }

    std::string_view header_view = {header};
    std::string_view header_without_prefix = header_view.substr(auth_header_prefix_end);

    auto parts = utils::split(header_without_prefix, ".");

    if (parts.size() == 2) {
        return {{
                        utils::decode_base_64(parts[0]),
                        utils::decode_base_64(parts[1]),
                }};
    }

    return {};
}

std::variant<route::Router::credentials_t, int> route::Router::authorize(HttpRequest *req, HttpResponse *resp) {
    nlohmann::json request;
    nlohmann::json response;

    try {
        std::string token = req->GetHeader("Authorization", "");

        auto credentials = parse_auth_header(token);
        if (!credentials) {
            response["error"] = "unauthorized";
            resp->SetBody(response.dump());
            resp->SetHeader("WWW-Authenticate", "Basic realm=\"Access to staging site\"");
            resp->content_type = APPLICATION_JSON;
            return 401;
        }

        bool isAuth = userService.checkAuthorization(credentials->username, credentials->password);

        if (!isAuth) {
            response["error"] = "unauthorized";
            resp->SetBody(response.dump());
            resp->SetHeader("WWW-Authenticate", "Basic");
            resp->content_type = APPLICATION_JSON;
            return 401;
        }

        return {std::move(credentials.value())};
    }
    catch (const std::exception &e) {
        response["error"] = e.what();
        resp->SetBody(response.dump());
        resp->content_type = APPLICATION_JSON;
        return 400;
    }
}

void route::Router::RegisterResources(hv::HttpService &router) {
    router.PUT("/user/{userId}", [this](HttpRequest *req, HttpResponse *resp) {
        auto authResult = authorize(req, resp);
        if (std::holds_alternative<int>(authResult)) {
            return std::get<int>(authResult);
        }

        auto &&credentials = std::get<route::Router::credentials_t>(std::move(authResult));

        nlohmann::json request;
        nlohmann::json response;

        try {
            request = nlohmann::json::parse(req->body);

            std::string uuid = req->GetParam("userId");

            auto updateUserUsername = request["username"];
            auto updateUserPassword = request["password"];
            auto updateUserRole = request["role"];

            auto user = userService.updateUser(credentials.username, uuid, updateUserUsername, updateUserPassword,
                                               updateUserRole);

            resp->SetBody(user.toJson().dump());
            resp->content_type = APPLICATION_JSON;

            return 200;
        } catch (const std::exception &e) {
            response["error"] = e.what();
            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;
            return 400;
        }
    });

    router.POST("/user", [this](HttpRequest *req, HttpResponse *resp) {
        auto authResult = authorize(req, resp);
        if (std::holds_alternative<int>(authResult)) {
            return std::get<int>(authResult);
        }

        nlohmann::json request;
        nlohmann::json response;

        try {
            request = nlohmann::json::parse(req->body);

            std::string username = request["username"];
            std::string password = request["password"];
            std::string role = request["role"];

            User user = userService.addUser(role, username, password);

            resp->SetBody(user.toJson().dump());
            resp->content_type = APPLICATION_JSON;

            return 200;
        }
        catch (const std::exception &e) {
            response["error"] = e.what();
            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;
            return 400;
        }
    });

    router.GET("/user", [this](HttpRequest *req, HttpResponse *resp) {
        auto authResult = authorize(req, resp);
        if (std::holds_alternative<int>(authResult)) {
            return std::get<int>(authResult);
        }
        auto &&credentials = std::get<route::Router::credentials_t>(std::move(authResult));

        nlohmann::json request;
        nlohmann::json response;

        try {
            auto user = userService.getUserByUsername(credentials.username);
            resp->SetBody(user.toJson().dump());

            return 200;
        }
        catch (const std::exception &e) {
            response["error"] = e.what();
            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;
            return 400;
        }
    });

    router.GET("/user/{userId}", [this](HttpRequest *req, HttpResponse *resp) {
        nlohmann::json response;

        try {
            std::string uuid = req->GetParam("userId");
            auto user = userService.getUser(uuid);

            response = user.toJson();

            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;

            return 200;
        }
        catch (const std::exception &e) {
            response["error"] = e.what();
            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;
            return 400;
        }
    });

    router.GET("/users", [this](HttpRequest *req, HttpResponse *resp) {
        nlohmann::json response;

        try {
            std::vector<User> users = userService.getUsers();

            for (const auto &user: users) {
                response.push_back(user.toJson());
            }

            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;

            return 200;
        }
        catch (const std::exception &e) {
            response["error"] = e.what();
            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;
            return 400;
        }
    });

    router.Delete("/user/{userId}", [this](HttpRequest *req, HttpResponse *resp) {
        auto authResult = authorize(req, resp);
        if (std::holds_alternative<int>(authResult)) {
            return std::get<int>(authResult);
        }
        auto &&credentials = std::get<route::Router::credentials_t>(std::move(authResult));

        nlohmann::json response;

        try {
            std::string uuid = req->GetParam("userId");
            auto deletedUser = userService.deleteUser(uuid, credentials.username);

            resp->SetBody(deletedUser.toJson().dump());
            resp->content_type = APPLICATION_JSON;

            return 200;
        } catch (const std::exception &e) {
            response["error"] = e.what();
            resp->SetBody(response.dump());
            resp->content_type = APPLICATION_JSON;
            return 400;
        }
    });
}