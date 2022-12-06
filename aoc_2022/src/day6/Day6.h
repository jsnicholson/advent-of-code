#pragma once
#include "Day.h"
#include <string>

class Day6 : public Day {
public:
	std::string m_signal;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	bool StringHasNoDuplicates(std::string);
	int FindFirstUniqueStringOfLengthN(std::string string, int length);
};