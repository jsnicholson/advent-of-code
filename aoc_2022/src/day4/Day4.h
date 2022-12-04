#pragma once
#include "Day.h"

class Day4 : public Day {
public:
	typedef std::pair<int, int> range;
	typedef std::pair<range, range> rangepair;
	std::list<rangepair> m_pairsOfCleaningRanges;

private:
	void Parse() override;
	int Part1() override;
	int Part2() override;
};