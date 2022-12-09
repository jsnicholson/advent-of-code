#pragma once
#include "Day.h"

#include <string>
#include <set>

class Day9 : public Day {
public:
	typedef std::pair<char, int> instruction;
	typedef std::pair<int, int> coordinate;
	std::vector<instruction> m_instructions;
	std::set<coordinate> m_placesTailHasBeen;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

private:
	bool AreTwoCoordsTouching(coordinate, coordinate);
	coordinate DirectionCommandToDirection(char);
	void MoveCoordTowards(coordinate&, const coordinate);
};

std::pair<int, int> operator+(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs);
std::pair<int, int> operator-(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs);
std::pair<int, int> operator*(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs);