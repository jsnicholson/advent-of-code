#pragma once
#include "Day.h"

#include <list>

// Sonar Sweep

class Day1 : public Day {
private:
	std::list<int> depths;

private:
	void Parse() override;
	int Part1() override;
	int Part2() override;

private:
	int HowManyIncreased(std::list<int> numbers);
};