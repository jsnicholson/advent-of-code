#pragma once
#include "Day.h"
#include <string>

class Day9 : public Day {

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;
};