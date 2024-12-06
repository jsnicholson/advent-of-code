#pragma once
#include "Day.h"

class Day4 : public Day {
public:
	const std::string WORD = "XMAS";
	std::vector<std::string> m_allPossibleLines;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;
};