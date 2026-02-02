#include <iostream>
#include "redis_server.h"

int main() {
    std::cout << "Build Your Own Redis - C++ Implementation" << std::endl;
    
    RedisServer server;
    std::cout << "Server initialized on port " << server.getPort() << std::endl;
    std::cout << "PING -> " << server.ping() << std::endl;
    
    return 0;
}
