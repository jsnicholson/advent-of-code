#pragma once
#include "Day.h"
#include <string>
#include <list>
#include <bitset>

class Day3 : public Day {
private:
	void Parse() override;
	int Part1() override;
	int Part2() override;

private:
	static const size_t bitsetLength = 12;
	std::list<std::bitset<bitsetLength>> listBitset;

private:
	int MostCommonBitInPosition(size_t position, std::list<std::bitset<bitsetLength>> list);


};