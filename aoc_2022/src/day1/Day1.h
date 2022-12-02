#pragma once
#include "Day.h"

#include <vector>

class Day1 : public Day {
public:
	std::vector<std::vector<int>> m_vecCaloriesPerElf;

public:
	void Parse() override;
	int Part1() override;
	int Part2() override;

public:
	std::vector<int> SumEachElfsCalories();
};