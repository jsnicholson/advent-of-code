#pragma once
#include "Day.h"

#include <vector>

class Day1 : public Day {
public:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;
};