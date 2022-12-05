#pragma once
#include "Day.h"

#include <stack>
#include <vector>

class Day5 : public Day {
public:
	typedef std::stack<char> cratestack;
	// how many to move by, from stack to stack
	typedef std::pair<int, std::pair<int,int>> instruction;

	std::vector<cratestack> m_cratestacks;
	std::vector<instruction> m_instructions;

private:
	void Parse() override;
	int Part1() override;
	int Part2() override;

public:
	std::vector<std::string> Split(std::string string, std::string delimiter);
	std::vector<std::string> Split(std::string string, char delimiter);

	instruction ParseInstruction(std::string);
};