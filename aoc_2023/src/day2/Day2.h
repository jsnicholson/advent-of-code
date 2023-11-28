#pragma once
#include "Day.h"

#include <list>

class Day2 : public Day {
public:
	typedef std::pair<char, char> round;
	std::list<round> m_rounds;

public:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	static int CalculateRoundScore(round round);
	static char CalculateWhatToPlay(round round);
};