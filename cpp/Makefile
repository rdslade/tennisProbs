CXX = g++

CXXFLAGS = -Wall -Werror -pedantic --std=c++11 -g

all: test

test : Player_tests.exe
	./Player_tests.exe

Player_tests.exe: Player.cpp Player_tests.cpp unit_test_framework.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

.SUFFIXES:

.PHONY: clean
clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump
