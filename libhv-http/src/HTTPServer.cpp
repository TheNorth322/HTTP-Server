#include "HTTPServer.hpp"
#include "repository/MapUserRepository.hpp"
#include "service/UserService.hpp"
#include "utility/UUIDv4Generator.hpp"

#include <thread>


HttpServer::HttpServer() : _router(
        UserService(std::make_unique<UUIDv4Generator>(), std::make_unique<MapUserRepository>())),
                           _server(std::make_unique<hv::HttpServer>()),
                           _service() {
//    _server = std::make_unique<hv::HttpServer>();
//    auto a = route::Router(UserService(std::move(uuidGenerator), std::move(userRepository)));
////    _router = route::Router(UserService(std::move(uuidGenerator), std::move(userRepository)));

    _router.RegisterResources(_service);
    _server->registerHttpService(&_service);
}

void HttpServer::Start(int port) {
    _router.userService.addUser("Admin", "admin", "admin");

    _server->setPort(port);
    _server->setThreadNum(std::thread::hardware_concurrency());
    _server->run();
}

HttpServer::~HttpServer() {
    _server->stop();
}