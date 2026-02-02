# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude
LDFLAGS = 

# Directories
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
BUILD_DIR = build
BIN_DIR = bin

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES))
MAIN_OBJECT = $(BUILD_DIR)/main.o
LIB_OBJECTS = $(filter-out $(MAIN_OBJECT),$(OBJECTS))

# Test files
TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SOURCES))
TEST_EXECUTABLES = $(patsubst $(TEST_DIR)/%.cpp,$(BIN_DIR)/%,$(TEST_SOURCES))

# Main executable
EXECUTABLE = $(BIN_DIR)/redis-server

# Default target
.PHONY: all
all: $(EXECUTABLE)

# Create directories
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Build main executable
$(EXECUTABLE): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile test files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Build tests
$(BIN_DIR)/%: $(BUILD_DIR)/%.o $(LIB_OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Build all tests
.PHONY: build-tests
build-tests: $(TEST_EXECUTABLES)

# Run tests
.PHONY: test
test: build-tests
	@echo "Running all tests..."
	@for test in $(TEST_EXECUTABLES); do \
		echo ""; \
		echo "Running $$test..."; \
		./$$test || exit 1; \
	done
	@echo ""
	@echo "All tests passed!"

# Run the main program
.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Help target
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all          - Build the main executable (default)"
	@echo "  build-tests  - Build all test executables"
	@echo "  test         - Build and run all tests"
	@echo "  run          - Build and run the main program"
	@echo "  clean        - Remove all build artifacts"
	@echo "  help         - Show this help message"
