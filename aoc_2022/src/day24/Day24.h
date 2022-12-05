#pragma once
#include "Day.h"

#include <string>

class Day24 : public Day {

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;
};