#include "Day.h"

#include <iostream>

#include "Utils.hpp"

bool Day::LoadFile(const std::string inputfilename) {
	return Utils::ReadFile(inputfilename, data);
}

void Day::Run(const std::string inputfilename) {
	if(!LoadFile(inputfilename)) return;
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
