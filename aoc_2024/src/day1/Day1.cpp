#include "day1.h"

#include "Utils.hpp"

#include <algorithm>
#include <math.h>

void Day1::Parse() {
	for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++) {
		std::string line = *it;
		auto tokens = Utils::SplitOnWhitespace(line);
		// should only be 2 lists in this example
		m_leftList.push_back(std::stoi(tokens.front()));
		m_rightList.push_back(std::stoi(tokens.back()));
	}
}

std::string Day1::Part1() {
	std::vector<int> leftList = m_leftList, rightList = m_rightList;
	int result = 0;

	std::sort(leftList.begin(), leftList.end());
	std::sort(rightList.begin(), rightList.end());

	for (int i = 0; i < leftList.size(); i++) {
		result += std::abs(leftList.at(i) - rightList.at(i));
	}

	return std::to_string(result);
}

std::string Day1::Part2() {
	return std::string("unimplemented");
}