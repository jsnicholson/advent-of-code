#pragma once
#include "Day.h"

class Day5 : public Day {
public:
	struct rule {
		unsigned long sourceMin, sourceMax;
		unsigned long destinationMin;
	};

	typedef std::vector<rule> mapper;
	typedef std::map<unsigned long, unsigned long> improvedMapper;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	unsigned long MapValue(mapper mapper, unsigned long value);

public:
	std::vector<unsigned long> m_seedNumbers;
	std::vector<mapper> m_maps;
};