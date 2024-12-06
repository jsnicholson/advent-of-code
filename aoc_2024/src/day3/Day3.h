#pragma once
#include "Day.h"

class Day3 : public Day {
public:
	typedef std::string instruction;
	typedef std::pair<int, int> operands;

public:
	std::string m_program;

public:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	int ExecuteMultiply(instruction instruction);
	operands ExtractOperands(instruction instruction);
};