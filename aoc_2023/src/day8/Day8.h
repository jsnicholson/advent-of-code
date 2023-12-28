#pragma once
#include "Day.h"

#include <map>

class Day8 : public Day {
public:
	struct node {
		std::string name;
		std::string left;
		std::string right;
	};

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	std::string m_instructions;
	std::map<std::string, node> m_nodes;
};