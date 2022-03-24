TC_FOLDER = tests
EXT_IN = in
EXT_OUT = out
EXT_ANS = ans
EXECUTABLE_FILENAME = main
ALL_SRCS := $(wildcard *.cpp Crafting/*.cpp Inventory/*.cpp Exception/*.cpp Item/*.cpp)
SRCS     := $(filter-out check.cpp, $(ALL_SRCS))

all: compile

# Compile all cpp files except check.cpp
compile:
	g++ -std=c++17 -o $(EXECUTABLE_FILENAME) $(SRCS)
	clear
	./main

FORCE: ;
