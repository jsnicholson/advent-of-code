#include <iostream>
#include "Days.hpp"

int main(int argc, char* argv[]) {
	
	std::cout << "Advent of Code : Day 1" << std::endl;

	Day* day = new Day1();
	day->Run();

	return 0;
}