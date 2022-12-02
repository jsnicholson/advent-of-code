#pragma once
#include "Day.h"

class Day2 : public Day {
public:
	typedef std::pair<char, char> round;
	std::list<round> m_rounds;

public:
	void Parse() override;
	int Part1() override;
	int Part2() override;

public:
	static int CalculateRoundScore(round round);
};