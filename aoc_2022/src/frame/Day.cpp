#include "Day.h"

#include <iostream>

#include "Utils.hpp"

bool Day::LoadFile(const std::string inputfilename) {
	return Utils::ReadFile(inputfilename, data);
}

void Day::Run(const std::string inputfilename) {
	if(!LoadFile(inputfilename)) return;
	Parse();

	std::cout << "Part1: " << Part1() << std::endl;
	std::cout << "Part2: " << Part2() << std::endl;
}

std::string Day::Part1() {
    return std::string("unimplemented");
}

std::string Day::Part2() {
    return std::string("unimplemented");
}
