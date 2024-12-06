#pragma once
#include "Day.h"

class Day2 : public Day {
public:
	typedef std::vector<int> report;
	const int MIN = 1, MAX = 3;

public:
	std::vector<report> m_reports;

public:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	bool IsReportSafe(report report);
	int GetDirection(int a, int b);
	bool InSafeRange(int a, int b);
	bool CanReportBeSafe(report report);
};