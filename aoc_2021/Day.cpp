#include "Day.h"
#include "Utils.hpp"
#include <iostream>

void Day::Run() {
	Utils::ReadFile(GetInput().c_str(), data);
	Parse();

	std::cout << "1:" << std::to_string(Part1()) << std::endl;
	std::cout << "2:" << std::to_string(Part2()) << std::endl;
}

int Day::Part1() {
    return -1;
}

int Day::Part2() {
    return -1;
}
