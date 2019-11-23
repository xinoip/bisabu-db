# Recursive wildcard function
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC := $(wildcard src/*.cpp)
SRC := $(filter-out src/main.cpp, $(SRC))

MAIN = $(wildcard src/main.cpp)

TESTS = $(call rwildcard, tests, *.cpp)

CC = g++
COMPILER_FLAGS = -Wall -Wextra
LINKER_FLAGS =

BUILD_DIR = ./build
OBJ_NAME = ./build/app
TEST_NAME = ./build/test

all : $(SRC)
	if [ ! -d "$(BUILD_DIR)" ]; then echo "Creating build directory." && mkdir $(BUILD_DIR);  fi; echo "Build directory exists, building project.";
	echo "Building project."
	$(CC) $(SRC) $(MAIN) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

test : $(SRC) $(TESTS)
	if [ ! -d "$(BUILD_DIR)" ]; then echo "Creating build directory." && mkdir $(BUILD_DIR);  fi; echo "Build directory exists, building project.";
	echo "Building tests."
	$(CC) $(TESTS) $(SRC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(TEST_NAME) -g
	