CXX = g++

CXXFLAGS = -Wall -Werror -pedantic --std=c++11 -g

Player_tests.exe: Player.cpp Player_tests.cpp unit_test_framework.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

stats_tests.exe: stats.cpp stats_tests.cpp unit_test_framework.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

Match_tests.exe: Match.cpp Player.cpp stats.cpp Match_tests.cpp unit_test_framework.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

main.exe: main.cpp Match.cpp Player.cpp stats.cpp
		$(CXX) $(CXXFLAGS) $^ -o $@

.SUFFIXES:

.PHONY: clean
clean:
	rm -rvf *.out *.exe *.dSYM *.stackdump
