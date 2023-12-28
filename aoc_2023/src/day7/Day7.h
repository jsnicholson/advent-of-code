#pragma once
#include "Day.h"

#include <map>

class Day7 : public Day {
public:
	struct play {
		std::string hand;
		int bid;
	};

	enum type {
		high_card = 0,
		one_pair = 1,
		two_pair = 2,
		three_of_a_kind = 3,
		full_house = 4,
		four_of_a_kind = 5,
		five_of_a_kind = 6
	};

	static inline const std::map<char, int> m_mapNonNumericCardValueToNumber = {
		{'A',14},
		{'K',13},
		{'Q',12},
		{'J',11},
		{'T',10}
	};

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	static type GetHandType(std::string hand);
	static std::vector<std::pair<char,int>> GetCharacterDistribution(std::string str);
	static bool CompareRank(const std::pair<play, type>& a, const std::pair<play, type>& b);
	static int GetCardValue(const char c);
	static int CalculateWinnings(const std::vector<std::pair<play, type>> rankedPlays);

public:
	std::vector<play> m_plays;
};