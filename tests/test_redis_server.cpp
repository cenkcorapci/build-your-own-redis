#include <iostream>
#include <string>
#include "../include/redis_server.h"

// Simple test framework
int tests_run = 0;
int tests_passed = 0;
int tests_failed = 0;

#define ASSERT_EQ(expected, actual, test_name) \
    do { \
        tests_run++; \
        auto exp_val = (expected); \
        auto act_val = (actual); \
        if (exp_val == act_val) { \
            std::cout << "[PASS] " << test_name << std::endl; \
            tests_passed++; \
        } else { \
            std::cout << "[FAIL] " << test_name << std::endl; \
            std::cout << "  Expected: " << exp_val << std::endl; \
            std::cout << "  Actual: " << act_val << std::endl; \
            tests_failed++; \
        } \
    } while (0)

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
