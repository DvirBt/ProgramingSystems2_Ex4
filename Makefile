# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -I.

# Executables
MAIN_EXEC = Main
TEST_EXEC = Tests  # Changed from "Tests"

# Source files
MAIN_SRC = main.cpp
TEST_SRC = Test/Tests.cpp

# Header file
HEADERS = MyContainer.hpp

# Targets
.PHONY: all Main test valgrind clean

all: Main test

Main: $(MAIN_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(MAIN_SRC) -o $(MAIN_EXEC)

test: $(TEST_SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(TEST_EXEC)

valgrind: test
	valgrind --leak-check=full --track-origins=yes ./$(TEST_EXEC)

clean:
	rm -f $(MAIN_EXEC) $(TEST_EXEC)
