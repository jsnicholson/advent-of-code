#include "Day2.h"

#include "Utils.hpp"

void Day2::Parse() {
	for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++) {
		std::string line = *it;
		std::vector<std::string> tokens = Utils::SplitOnWhitespace(line);
		m_reports.push_back(Utils::ToVectorInt(tokens));
	}
}

std::string Day2::Part1() {
	int count = 0;

	for (std::vector<report>::const_iterator it = m_reports.begin(); it != m_reports.end(); it++) {
		count += IsReportSafe(*it);
	}

	return std::to_string(count);
}

std::string Day2::Part2() {
	return std::string("unimplemented");
}

bool Day2::IsReportSafe(report report) {
	int initialDirection = Day2::GetDirection(report[0], report[1]);

	for (Day2::report::iterator it = report.begin() + 1; it != report.end(); it++) {
		int currentDirection = Day2::GetDirection(*(it - 1), *it);
		if (currentDirection != initialDirection) return false;

		if(!InSafeRange(*(it - 1), *it)) return false;
	}

	return true;
}

int Day2::GetDirection(int a, int b) {
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}

bool Day2::InSafeRange(int a, int b) {
	int difference = std::abs(a - b);
	if (difference >= Day2::MIN && difference <= Day2::MAX) return true;
	return false;
}
