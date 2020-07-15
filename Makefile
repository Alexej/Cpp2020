CXX = g++

# [TOPIC](3) Toolchain: Fehler und Warnings*
CXXFLAGS = -Wall -Werror -Wextra -Wpedantic -std=c++20 -g
LDFLAGS = -fsanitize=address
DEBUG = -DVERBOSE
TESTS = -DTESTS

#https://blog.jgc.org/2011/07/gnu-make-recursive-wildcard-function.html
rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

BIN = ./bin/
SOURCES = $(call rwildcard,./src/,*.cpp)

TEST_SOURCES := $(SOURCES)
TEST_SOURCES += ./tests/tests.cpp

OBJ = $(SOURCES:.cc=.o)
TEST_OBJ = $(TEST_SOURCES:.cc=.o)

EXEC = bin/cress
TEST_EXEC = bin/cress_tests
VERBOSE_EXEC = bin/cress_verbose
BENCHAMRK_EXEC = bin/cress_benchmark

all: $(EXEC)
$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS) 

verbose: $(VERBOSE_EXEC)
$(VERBOSE_EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS) $(DEBUG)

tests: $(TEST_EXEC)
$(TEST_EXEC): $(TEST_OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(TEST_OBJ) $(LBLIBS) $(TESTS)

clear:
	rm ./bin/*