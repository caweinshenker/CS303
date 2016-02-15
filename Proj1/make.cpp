CC = g++
CCFLAGS = -O -g -std=c++11 -Wall -pedantic 

sort: main.cpp sort_utils.cpp sort.cpp sort.hpp
	$(CC) $(CCFLAGS) -o sort main.cpp sort_utils.cpp sort.cpp
