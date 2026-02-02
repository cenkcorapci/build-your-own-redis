#ifndef REDIS_SERVER_H
#define REDIS_SERVER_H

#include <string>

class RedisServer {
public:
    RedisServer();
    ~RedisServer();
    
    std::string ping();
    int getPort() const;
    
private:
    int port;
};

#endif // REDIS_SERVER_H
