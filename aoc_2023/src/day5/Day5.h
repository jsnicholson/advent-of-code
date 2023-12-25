#pragma once
#include "Day.h"

#include <map>

class Day5 : public Day {
public:
	typedef unsigned long long ull;
	typedef std::pair<ull, ull> pull;

	struct rule {
		ull sourceStart;
		ull destinationStart;
		ull length;
	};

	typedef std::vector<rule> mapping;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	ull MapValue(mapping mapper, ull value);
	ull CalculateLocation(ull seed);
	std::vector<pull> LookUp(std::vector<pull> keyRanges,mapping mapper);
	ull GetMin(ull current, const std::vector<pull>& ranges);

public:
	std::vector<ull> m_seedNumbers;
	std::vector<mapping> m_maps;
};