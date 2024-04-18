# Makefile for Generate.cpp

# Compiler
CC = g++

# Compiler flags
CFLAGS = -ggdb3 -Wall -Wextra -std=c++17 -fopenmp -march=native -O3 -ltbb

all: Generate Sort

Generate: Generate.cpp
	$(CC) $(CFLAGS) -o Generate Generate.cpp

Sort: Sort.cpp
	$(CC) $(CFLAGS) -o Sort Sort.cpp

clean:
	rm -f Generate Sort