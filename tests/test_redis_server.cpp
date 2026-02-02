#include <iostream>
#include <string>
#include "../include/redis_server.h"

// Simple test framework
int tests_run = 0;
int tests_passed = 0;
int tests_failed = 0;

#define ASSERT_EQ(expected, actual, test_name) \
    tests_run++; \
    if ((expected) == (actual)) { \
        std::cout << "[PASS] " << test_name << std::endl; \
        tests_passed++; \
    } else { \
        std::cout << "[FAIL] " << test_name << std::endl; \
        std::cout << "  Expected: " << (expected) << std::endl; \
        std::cout << "  Actual: " << (actual) << std::endl; \
        tests_failed++; \
    }

void test_redis_server_ping() {
    RedisServer server;
    ASSERT_EQ(std::string("PONG"), server.ping(), "RedisServer::ping returns PONG");
}

void test_redis_server_port() {
    RedisServer server;
    ASSERT_EQ(6379, server.getPort(), "RedisServer default port is 6379");
}

int main() {
    std::cout << "Running Redis Server Tests..." << std::endl;
    std::cout << "================================" << std::endl;
    
    test_redis_server_ping();
    test_redis_server_port();
    
    std::cout << "================================" << std::endl;
    std::cout << "Tests run: " << tests_run << std::endl;
    std::cout << "Tests passed: " << tests_passed << std::endl;
    std::cout << "Tests failed: " << tests_failed << std::endl;
    
    return tests_failed;
}
