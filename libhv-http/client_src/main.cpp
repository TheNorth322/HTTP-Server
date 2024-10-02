#include <iostream>
#include <iomanip>
#include "requests.h"
#include "Base64Encoder.h"

constexpr const char *const url = "localhost:7777";

std::string create_auth_header(const std::string &username, const std::string &password) {
    std::string encoded_username = utils::encode_base_64(username);
    std::string encoded_password = utils::encode_base_64(password);

    return "Basic " + encoded_username + "." + encoded_password;
}

std::string get_auth_data() {
    std::string username;
    std::string password;

    std::cout << "authorization:\n";
    std::cout << "username: ";
    std::cin >> username;

    std::cout << "password: ";
    std::cin >> password;

    return create_auth_header(username, password);
}

int getMenuOption() {
    std::cout << "1 - get users" << std::endl;
    std::cout << "2 - get user (self)" << std::endl;
    std::cout << "3 - get user by uuid" << std::endl;
    std::cout << "4 - change user by uuid" << std::endl;
    std::cout << "5 - add user" << std::endl;
    std::cout << "6 - delete user by uuid" << std::endl;
    std::cout << "7 - exit" << std::endl;

    int menu_option;
    std::cout << "option: ";
    std::cin >> menu_option;

    if (menu_option < 1 or menu_option > 7) {
        throw std::runtime_error("invalid menu option");
    }

    return menu_option;
}

nlohmann::json handle_response(const HttpResponsePtr &resp, const std::string &error_msg) {
    if (resp == nullptr) {
        throw std::runtime_error(error_msg);
    }

    int status_code = static_cast<int>(resp->status_code);

    if (status_code < 200 || status_code >= 300) {
        throw std::runtime_error(
                error_msg + " status code: " + std::to_string(status_code) + ". response: " + resp->body);
    }

    return nlohmann::json::parse(resp->body);
}

void handle_get_users() {
    auto endpoint = std::string(url) + "/users";
    auto resp = handle_response(requests::get(endpoint.c_str()), "get users failed");
    std::cout << "users:\n" << std::setw(4) << resp.dump(4) << std::endl;
}

void handle_get_self_user() {
    auto endpoint = std::string(url) + "/user";
    std::map<std::string, std::string, hv::StringCaseLess> headers{
            {"Authorization", get_auth_data()},
    };

    auto resp_json = handle_response(requests::get(endpoint.c_str(), headers), "get self user failed!");
    std::cout << "user:\n" << std::setw(4) << resp_json.dump(4) << std::endl;
}

void handle_get_user_by_uuid() {
    std::string uuid;

    std::cout << "user uuid: ";
    std::cin >> uuid;

    auto endpoint = std::string(url) + "/user/" + uuid;

    auto resp_json = handle_response(requests::get(endpoint.c_str()), "get user by uuid " + uuid + " failed!");
    std::cout << "user:\n" << std::setw(4) << resp_json.dump(4) << std::endl;
}

void handle_change_user_by_uuid() {
    auto auth_data = get_auth_data();

    std::string uuid;
    std::string username;
    std::string password;
    std::string role;

    std::cout << "user uuid: ";
    std::cin >> uuid;

    std::cout << "new username: ";
    std::cin >> username;

    std::cout << "new password: ";
    std::cin >> password;

    std::cout << "new role (only admin can change role): ";
    std::cin >> role;

    auto endpoint = std::string(url) + "/user/" + uuid;
    std::map<std::string, std::string, hv::StringCaseLess> headers{
            {"Authorization", auth_data},
    };
    nlohmann::json body{
            {"username", username},
            {"password", password},
            {"role",     role},
    };
    auto resp_json = handle_response(requests::put(endpoint.c_str(), body.dump(), headers),
                                     "change user by uuid \"" + uuid + "\" failed!");
    std::cout << "updated user:\n" << std::setw(4) << resp_json.dump(4) << std::endl;
}

void handle_add_user() {
    auto auth_data = get_auth_data();

    std::string username;
    std::string password;
    std::string role;

    std::cout << "username: ";
    std::cin >> username;

    std::cout << "password: ";
    std::cin >> password;

    std::cout << "role: ";
    std::cin >> role;

    auto endpoint = std::string(url) + "/user";
    std::map<std::string, std::string, hv::StringCaseLess> headers{
            {"Authorization", auth_data},
    };
    nlohmann::json body{
            {"username", username},
            {"password", password},
            {"role",     role},
    };
    auto resp_json = handle_response(requests::post(endpoint.c_str(), body.dump(), headers),
                                     "failed to add user!");
    std::cout << "new user:\n" << std::setw(4) << resp_json.dump(4) << std::endl;
}

void handle_delete_user_by_uuid() {
    auto auth_data = get_auth_data();

    std::string uuid;
    std::string username;
    std::string password;
    std::string role;

    std::cout << "user uuid: ";
    std::cin >> uuid;

    auto endpoint = std::string(url) + "/user/" + uuid;
    std::map<std::string, std::string, hv::StringCaseLess> headers{
            {"Authorization", auth_data},
    };

    auto resp_json = handle_response(requests::Delete(endpoint.c_str(), headers),
                                     "change user by uuid \"" + uuid + "\" failed!");
    std::cout << "deleted user:\n" << std::setw(4) << resp_json.dump(4) << std::endl;
}

int main() {
    while (true) {
        try {
            switch (getMenuOption()) {
                case 1:
                    handle_get_users();
                    break;
                case 2:
                    handle_get_self_user();
                    break;
                case 3:
                    handle_get_user_by_uuid();
                    break;
                case 4:
                    handle_change_user_by_uuid();
                    break;
                case 5:
                    handle_add_user();
                    break;
                case 6:
                    handle_delete_user_by_uuid();
                    break;
                case 7:
                    return 0;
            }
        } catch (const std::exception &ex) {
            std::cout << "error: " << ex.what() << std::endl;
        }
    }
}