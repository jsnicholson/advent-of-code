#pragma once
#include "Day.h"
#include <string>
#include <list>

// Submarine driving

typedef std::list<std::pair<std::string, int>> list_commands;

class Day2 : public Day {
private:
	list_commands commands;

private:
	void Parse() override;
	int Part1() override;
	int Part2() override;
};