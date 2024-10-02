#ifndef _ROUTERS_HPP_
#define _ROUTERS_HPP_

#include "HttpService.h"
#include "repository/UserRepository.hpp"
#include "service/UserService.hpp"
#include <variant>

namespace route
{
    class Router {
    public:
        explicit Router(UserService userService) : userService(std::move(userService)) {}

        void RegisterResources(hv::HttpService &router);

        UserService userService;
    private:
        struct credentials_t {
            std::string username;
            std::string password;
        };

        static std::optional<credentials_t> parse_auth_header(const std::string &header);

        std::variant<credentials_t, int> authorize(HttpRequest *req, HttpResponse *resp);
    };
}

#endif