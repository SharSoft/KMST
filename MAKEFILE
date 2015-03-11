FL=g++
FLSFLAGS=-w
BIN=prog2
SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)
all: $(OBJ)
	$(FL) -o $(BIN) $^
%.o: %.c
	$(FL) $@ -c $<
