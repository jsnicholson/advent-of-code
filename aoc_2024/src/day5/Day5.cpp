#include "Day5.h"

#include "Utils.hpp"

void Day5::Parse() {
	// fill rules
	std::vector<std::string>::const_iterator it;
	for (it = data.begin(); it != data.end() && !it->empty(); it++) {
		auto tokens = Utils::Split(*it, '|');
		Day5::m_mapRules[std::stoi(tokens.front())].push_back(std::stoi(tokens.back()));
	}
	
	// fill updates
	for (it; it != data.end(); it++) {
		if (it->empty()) continue;

		auto tokens = Utils::Split(*it, ',');
		update update = Utils::ToVectorInt(tokens);
		m_updates.push_back(update);
	}
}

std::string Day5::Part1() {
	int middlePageSum = 0;

	for (auto it = Day5::m_updates.begin(); it != m_updates.end(); it++) {
		if (Day5::IsUpdateValid(*it))
			middlePageSum += GetMiddlePage(*it);
	}

	return std::to_string(middlePageSum);
}

std::string Day5::Part2() {
	return std::string("unimplemented");
}

bool Day5::IsUpdateValid(const update& update) {
	for (auto it = update.rbegin(); it != update.rend() - 1; it++) {
		auto rulesExist = Day5::m_mapRules.find(*it);
		if (rulesExist == Day5::m_mapRules.end())
			break;

		auto disallowedPreceedingNumbers = rulesExist->second;

		const Day5::update subVector(update.begin(), it.base() - 1);
		if (Utils::AnyCommonElement(disallowedPreceedingNumbers, subVector))
			return false;
	}
	
	return true;
}

int Day5::GetMiddlePage(const update& update) {
	size_t middleIndex = std::ceil(update.size() / 2);
	return update[middleIndex];
}
