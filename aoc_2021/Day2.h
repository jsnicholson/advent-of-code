#pragma once
#include <vector>
#include <string>
#include <list>

class Day2
{
	typedef std::list<std::pair<std::string, int>> list_commands;

public:
	void Run(const char* filename);

private:
	void Parse(const char* filename, list_commands& lines);
	int Part1(list_commands numbers);
	int Part2(list_commands numbers);
};