#pragma once
#include "Day.h"

class Day4 : public Day {
public:
	struct card {
		int id;
		std::vector<int> winningNumbers;
		std::vector<int> playedNumbers;
	};

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	int CalculateCardMatches(card card);

public:
	std::vector<card> m_cards;
};