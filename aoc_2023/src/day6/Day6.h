#pragma once
#include "Day.h"

class Day6 : public Day {
public:
	typedef unsigned long long ull;
	struct race {
		ull length;
		ull distance;
	};

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	ull SolveForDistance(ull raceLength, ull timeButtonHeld);
	std::pair<double, double> SolveForTime(ull raceLength, ull raceDistance);
	ull CalculateWaysToBeat(race race);
	race ConcatenateRaces();

public:
	std::vector<race> m_races;
};