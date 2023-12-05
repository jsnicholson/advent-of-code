#pragma once
#include "Day.h"

#include <list>

class Day2 : public Day {
public:
	struct round {
		int red;
		int green;
		int blue;
	};
	struct game {
		int id;
		std::vector<round> rounds = std::vector<round>();
	};

public:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	std::vector<game> m_games;
	int maxRed = 12;
	int maxGreen = 13;
	int maxBlue = 14;
};