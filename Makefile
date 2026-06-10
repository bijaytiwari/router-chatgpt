CXX=g++
CXXFLAGS=-std=c++20 -Wall -Wextra -pthread -Iinclude
SRC=$(wildcard src/*.cpp)
router:
	$(CXX) $(CXXFLAGS) $(SRC) -o router
