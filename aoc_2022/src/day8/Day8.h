#pragma once
#include "Day.h"

#include <string>
#include <vector>

class Day8 : public Day {
public:
	std::vector<std::vector<int>> m_trees;
	

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	void CalculateVisibilityFromLeft(const std::vector<std::vector<int>>& trees, std::vector<std::vector<int>>& visibility);
	void Rotate(std::vector<std::vector<int>>& matrix);
	int CalculateScenicScore(const std::vector<std::vector<int>>& trees, std::pair<int,int> tree);
	bool PairInRange(std::pair<int, int> min, std::pair<int, int> max, std::pair<int, int> value);
	std::pair<int,int> GetStartingCoord(const std::pair<int, int> coord, const std::pair<int,int> direction);
	void AdvanceCoordInDirection(std::pair<int, int>& coord, std::pair<int, int> direction);
};