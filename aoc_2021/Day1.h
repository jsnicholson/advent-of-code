#pragma once
#include <vector>
#include <string>
#include <list>

class Day1
{
public:
	void Run(const char* filename);

private:
	void Parse(const char* filename, std::list<int>& lines);
	int Part1();
	int Part2();

private:
	std::list<int> numbers;
};