#pragma once
#include "Day.h"

#include <map>

class Day3 : public Day {
public:
	struct part {
		int id;
		int value;
	};

public:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	int ProcessPotentialGear(int index);

public:
	std::vector<std::string> m_grid;
	std::string m_schematic;
	int m_indexNeighbours[8];
	std::map<int, part> m_mapPartNumbers;
};