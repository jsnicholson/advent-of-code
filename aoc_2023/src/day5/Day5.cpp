#include "Day5.h"

#include "Utils.hpp"

void Day5::Parse() {
    auto seedStrings = Utils::Split(data.front(), ' ');
    seedStrings.erase(seedStrings.begin());
    for (auto seedString : seedStrings) {
        m_seedNumbers.push_back(std::stoul(seedString));
    }

    Day5::mapper mapper;
    for (std::vector<std::string>::iterator it = data.begin()+=3; it != data.end(); it++) {
        std::string line = *it;
        if (line.empty()) {
            m_maps.push_back(mapper);
            mapper.clear();
            it++;
            continue;
        }

        if (std::isdigit(line[0])) {
            auto ruleString = Utils::Split(line, ' ');
            auto destinationMin = std::stoul(ruleString[0]);
            auto sourceMin = std::stoul(ruleString[1]);
            auto range = std::stoul(ruleString[2]);
            rule rule;
            rule.sourceMin = sourceMin;
            rule.sourceMax = sourceMin + range;
            rule.destinationMin = destinationMin;
            mapper.push_back(rule);
            continue;
        }

        // is name line
        continue;
    }
    // push mapper that reached end of file
    m_maps.push_back(mapper);
}

std::string Day5::Part1() {
    unsigned long currentMin;
    for (auto seed : m_seedNumbers) {
        auto value = seed;
        for (std::vector<mapper>::iterator it = m_maps.begin(); it != m_maps.end(); it++) {
            value = MapValue(*it, value);
        }
        currentMin = std::min(currentMin, value);
    }
    return std::to_string(currentMin);
}

std::string Day5::Part2() {
    std::vector<std::pair<unsigned long, unsigned long>> ranges;
    unsigned long long totalToSearch = {0};
    for (std::vector<unsigned long>::iterator it = m_seedNumbers.begin(); it != m_seedNumbers.end(); it+=2) {
        unsigned long rangeStart = *it;
        unsigned long rangeLength = *(it + 1);
        ranges.push_back(std::make_pair(rangeStart,rangeStart+rangeLength));
        totalToSearch += rangeLength;
    }

    unsigned long currentMin;
    unsigned long long currentSearch = { 0 };
    for (auto range : ranges) {
        for (unsigned long i = range.first; i <= range.second; i++) {
            currentSearch += 1;
            std::cout << "currently searching " << currentSearch << " of " << totalToSearch << std::endl;
            auto value = i;
            for (std::vector<mapper>::iterator it = m_maps.begin(); it != m_maps.end(); it++) {
                value = MapValue(*it, value);
            }
            currentMin = std::min(currentMin, value);
        }
    }
    return std::to_string(currentMin);
}

unsigned long Day5::MapValue(mapper mapper, unsigned long value) {
    for (auto rule : mapper) {
        if (value >= rule.sourceMin
            && value <= rule.sourceMax) {
            unsigned long offset = value - rule.sourceMin;
            return rule.destinationMin + offset;
        }
    }
    return value;
}