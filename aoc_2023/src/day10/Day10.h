#pragma once
#include "Day.h"

#include <string>
#include <vector>
#include <map>

class Day10 : public Day {
public:
	std::vector<std::string> m_instructions;
	const int m_screenWidth = 40;

	typedef std::pair<int, int> state;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

	std::vector<state> ExecuteInstruction(int& cycle, int& xRegister, const std::string instruction);
	void StatesToInterestingSignalStrengths(const std::vector<state> states, std::map<int, int>& interestingSignalStrengths);
	void StatesToScreenOutput(const std::vector<state> states, std::string& output);
	bool IsPixelLit(const int xRegister, const int cathodeRayIndex);
};