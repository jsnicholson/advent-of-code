#pragma once
#include "Day.h"

#include <list>

class Day1 : public Day {
public:
	std::list<int> calories;

private:
	void Parse() override;
	int Part1() override;
	int Part2() override;
};