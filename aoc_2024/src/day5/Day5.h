#pragma once
#include "Day.h"

#include <map>

class Day5 : public Day {
public:
	typedef std::pair<int, int> rule;
	typedef std::vector<int> update;

public:
	std::map<int, std::vector<int>> m_mapRules;
	std::vector<update> m_updates;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	bool IsUpdateValid(const update& update);
	int GetMiddlePage(const update& update);
};