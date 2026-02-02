#include "redis_server.h"

RedisServer::RedisServer() : port(6379) {
}

RedisServer::~RedisServer() {
}

std::string RedisServer::ping() {
    return "PONG";
}

int RedisServer::getPort() const {
    return port;
}
