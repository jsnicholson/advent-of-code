#pragma once
#include "Day.h"

#include <vector>

class Day1 : public Day {
public:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	std::pair<char, char> FindFirstAndLastDigit(std::string line);
	size_t FindFirstDigit(std::string line);
	size_t FindLastDigit(std::string line);

public:
	std::vector<std::string> m_lines;
};