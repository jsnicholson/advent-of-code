#include "Day.h"

#include <iostream>

#include "Utils.hpp"

void Day::Run(std::string inputfilename) {
	if(!Utils::ReadFile(inputfilename, data)) return;
	Parse();

	std::cout << "Part1: " << std::to_string(Part1()) << std::endl;
	std::cout << "Part2: " << std::to_string(Part2()) << std::endl;
}

int Day::Part1() {
    return -1;
}

int Day::Part2() {
    return -1;
}
