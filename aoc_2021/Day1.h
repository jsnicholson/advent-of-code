#pragma once
#include "Day.h"
#include <list>

class Day1 : public Day {
private:
	std::list<int> depths;

private:
	void Parse() override;
	int Part1() override;
	int Part2() override;

private:
	int HowManyIncreased(std::list<int> numbers);

protected:
	std::string GetInput() { return "input_day1.txt"; };
};