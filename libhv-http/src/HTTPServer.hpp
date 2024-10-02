#ifndef _HTTP_SERVER_HPP_
#define _HTTP_SERVER_HPP_

#include "HttpServer.h"
#include "HttpService.h"

#include "Router.hpp"
#include "../contrib/libhv/examples/httpd/router.h"

class HttpServer final
{
public:
    using UPtr = std::unique_ptr<HttpServer>;

    HttpServer();
//    HttpServer() : _router(UserService(std::make_unique<UUIDV4Generator>(), std::make_unique<MapUserRepository>())) {}

    HttpServer(const HttpServer &) = delete;
    HttpServer(HttpServer &&) = delete;

    ~HttpServer();

    void Start(int port);

private:
    route::Router _router;
    std::unique_ptr<hv::HttpServer> _server;
    HttpService _service;
};

#endif