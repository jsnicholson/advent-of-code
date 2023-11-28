#pragma once
#include "Day.h"

#include <vector>

class Day1 : public Day {
public:
	std::vector<std::vector<int>> m_caloriesPerElf;

public:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	std::vector<int> SumEachElfsCalories();
};