# Build Your Own Redis

A C++ implementation of Redis based on the [CodeCrafters Redis challenge](https://app.codecrafters.io/courses/redis/overview).

## Project Structure

```
.
├── include/          # Header files
├── src/              # Source files
├── tests/            # Unit tests
├── Makefile          # Build configuration
└── README.md         # This file
```

## Prerequisites

- C++ compiler with C++11 support (g++ or clang++)
- make

## Building

To build the main executable:

```bash
make
```

This will create the `redis-server` executable in the `bin/` directory.

## Running

To build and run the server:

```bash
make run
```

Or run the executable directly:

```bash
./bin/redis-server
```

## Testing

To build and run all tests:

```bash
make test
```

To only build tests without running them:

```bash
make build-tests
```

Test executables will be created in the `bin/` directory.

## Available Make Targets

- `make all` (default) - Build the main executable
- `make build-tests` - Build all test executables
- `make test` - Build and run all tests
- `make run` - Build and run the main program
- `make clean` - Remove all build artifacts
- `make help` - Show available targets

## Cleaning

To remove all build artifacts:

```bash
make clean
```

## Adding New Tests

1. Create a new test file in the `tests/` directory (e.g., `tests/test_myfeature.cpp`)
2. Use the simple test framework with `ASSERT_EQ` macro:

```cpp
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

void test_my_feature() {
    ASSERT_EQ(expected_value, actual_value, "Test description");
}

int main() {
    std::cout << "Running My Feature Tests..." << std::endl;
    std::cout << "================================" << std::endl;
    
    test_my_feature();
    
    std::cout << "================================" << std::endl;
    std::cout << "Tests run: " << tests_run << std::endl;
    std::cout << "Tests passed: " << tests_passed << std::endl;
    std::cout << "Tests failed: " << tests_failed << std::endl;
    
    return tests_failed;
}
```

3. Run `make test` to build and run all tests

## Contributing

When adding new features:
1. Add header files to `include/`
2. Add implementation files to `src/`
3. Add corresponding test files to `tests/`
4. Run `make test` to ensure all tests pass
