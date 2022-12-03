#pragma once
#include "Day.h"

#include <list>

class Day3 : public Day {
public:
	typedef std::string rucksack;
	typedef std::pair<std::string, std::string> splitRucksack;
	std::list<std::string> m_rucksacks;

public:
	void Parse() override;
	int Part1() override;
	int Part2() override;

public:
	splitRucksack SplitRucksackIntoTwoEvenCompartments(rucksack);
	char FindRepeatedItemInRucksack(rucksack);
	int CalculateItemPriority(char);
	std::list<char> FindIntersectionOfThreeRucksacks(rucksack first, rucksack second, rucksack third);
};