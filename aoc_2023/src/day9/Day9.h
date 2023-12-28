#pragma once
#include "Day.h"

class Day9 : public Day {
private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	int PredictNextValue(const std::vector<int>);
	int PredictPreviousValue(const std::vector<int>);
	std::vector<int> CalculateDifferences(const std::vector<int>);

public:
	std::vector<std::vector<int>> m_measurements;
};