#pragma once
#include "Day.h"

#include <string>

class Day19 : public Day {

private:
	void Parse() override;
	int Part1() override;
	int Part2() override;

protected:
	std::string GetInput() { return "input_day1.txt"; };
};