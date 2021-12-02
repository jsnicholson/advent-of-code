#pragma once
#include "Day.h"
#include <string>
#include <list>

typedef std::list<std::pair<std::string, int>> list_commands;

class Day2 : public Day {
private:
	list_commands commands;

private:
	void Parse() override;
	int Part1() override;
	int Part2() override;

protected:
	std::string GetInput() { return "input_day2.txt"; };
};