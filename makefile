SRC = ./src/*.cpp
TESTS = ./tests/*/*.cpp ./tests/*.cpp

CC = g++
COMPILER_FLAGS = -Wall -Wextra
LINKER_FLAGS =

OBJ_NAME = ./build/app
TEST_NAME = ./build/test

all : $(SRC)
	$(CC) $(SRC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

test : $(SRC) $(TESTS)
	$(CC) $(SRC) $(TESTS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(TEST_NAME) -g
	