#pragma once
#include "Day.h"
#include <string>
#include <vector>

class Day4 : public Day {

private:
	void Parse() override;
	int Part1() override;
	int Part2() override;

private:
	std::vector<int> vectorBingoNumbers;
	std::vector<std::vector<int>> vectorWinningLines;

private:
	void BoardToVerticalWinningLines(std::vector<std::vector<int>>& board);

public:
	std::string GetInput() override { return std::string("resources\\day4_temp.txt"); }
};