#pragma once
#include "Day.h"

class Day6 : public Day {
public:
	struct race {
		int distance;
		int length;
	};

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	int SolveForDistance(int raceLength, int timeButtonHeld);
	std::pair<double, double> SolveForTime(int raceLength, int raceDistance);

public:
	std::vector<race> m_races;
};