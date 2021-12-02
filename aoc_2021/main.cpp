#include <iostream>
#include "Days.hpp"

int main(int argc, char* argv[]) {
	
	std::cout << "Advent of Code : Day 1" << std::endl;

	Day1* day = new Day1();
	day->Run("input_day1.txt");

	return 0;
}