#include <iostream>
#include "Days.hpp"

int main(int argc, char* argv[]) {
	
	std::cout << "Advent of Code : Day 1" << std::endl;

	Day2* day = new Day2();
	day->Run("input_day2.txt");

	return 0;
}