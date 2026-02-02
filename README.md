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
#include "../include/redis_server.h"

void test_my_feature() {
    ASSERT_EQ(expected_value, actual_value, "Test description");
}

int main() {
    test_my_feature();
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
