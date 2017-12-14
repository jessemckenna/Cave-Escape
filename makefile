#CC = gcc # C compiler
CXX = g++ # C++ compiler
#CFLAGS = -std=c99 # flag for C standard
CXXFLAGS = -std=c++0x # flag for C++ standard
CXXFLAGS += -Wall # turn on all errors
CXXFLAGS += -pedantic-errors # strictly enforce standard and generate errors when violated
CXXFLAGS += -g # for debugging
#CXXFLAGS += -O3 # for optimization; should not be enabled during debugging

LDFLAGS =  # linker flags

OBJS = main.o game.o board.o player.o space.o emptySpace.o exitSpace.o holeSpace.o wallSpace.o menu.o getInput.o

SRCS = main.cpp game.cpp board.cpp player.cpp space.cpp emptySpace.cpp exitSpace.cpp holeSpace.cpp wallSpace.cpp menu.cpp getInput.cpp

HEADERS = game.hpp board.hpp player.hpp space.hpp emptySpace.hpp exitSpace.hpp holeSpace.hpp wallSpace.hpp menu.hpp getInput.hpp

#target: dependencies
#	rule to build

# first target is default; will execute if just run "make"
main: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

# @:.o=.cpp is called an implicit rule
# tells compiler that source files end in .cpp, targets end in .o
# will build all .o files from .cpp files

# $() or ${} syntax replaces part of a rule, ex. g++, with a variable, ex. ${CXX}

.PHONY: clean
clean:
	rm main ${OBJS}

# .PHONY indicates that clean is not a file
