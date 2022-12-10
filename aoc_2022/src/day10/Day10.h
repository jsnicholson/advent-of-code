#pragma once
#include "Day.h"

#include <string>
#include <vector>
#include <map>

class Day10 : public Day {
public:
	std::vector<std::string> m_instructions;
	const int m_screenWidth = 40;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

	std::map<int,int> ProcessNoopCommand(int& cycle, const int xRegister);
	std::map<int,int> ProcessAddXCommand(const int addValue, int& cycle, int& xRegister);
	void UpdateInterestingValues(const std::map<int,int> signalStrengths, std::map<int,int>& interestingSignalStrengths);
	bool IsPixelLit(const int xRegister, const int cathodeRayIndex);
	void RunCycle(int& cycle);
	void ProduceScreenOutput(const int cycle, const int xRegister, std::string& output);
};