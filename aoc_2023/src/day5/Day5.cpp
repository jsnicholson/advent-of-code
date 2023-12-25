#include "Day5.h"

#include "Utils.hpp"

void Day5::Parse() {
    auto seedStrings = Utils::Split(data.front(), ' ');
    seedStrings.erase(seedStrings.begin());
    for (auto seedString : seedStrings) {
        m_seedNumbers.push_back(std::stoul(seedString));
    }

    Day5::mapping mapper;
    for (std::vector<std::string>::iterator it = data.begin() += 3; it != data.end(); it++) {
        std::string line = *it;
        if (line.empty()) {
            m_maps.push_back(mapper);
            mapper.clear();
            it++;
            continue;
        }

        if (std::isdigit(line[0])) {
            auto ruleString = Utils::Split(line, ' ');
            auto destinationStart = std::stoul(ruleString[0]);
            auto sourceStart = std::stoul(ruleString[1]);
            auto length = std::stoul(ruleString[2]);
            rule rule;
            rule.sourceStart = sourceStart;
            rule.length = length;
            rule.destinationStart = destinationStart;
            mapper.push_back(rule);
        }
    }
    // push mapper that reached end of file
    m_maps.push_back(mapper);
}

std::string Day5::Part1() {
    ull currentMin = ULLONG_MAX;
    for (auto seed : m_seedNumbers) {
        currentMin = std::min(currentMin, CalculateLocation(seed));
    }
    return std::to_string(currentMin);
}

std::string Day5::Part2() {
    std::vector<std::pair<ull,ull>> seedRanges;
    for (std::vector<ull>::iterator it = m_seedNumbers.begin(); it != m_seedNumbers.end(); it += 2) {
        ull rangeStart = *it;
        ull rangeLength = *(it + 1);
        seedRanges.push_back(std::make_pair(rangeStart, rangeLength));
    }

    ull globalMin = ULLONG_MAX;
    for (const auto& seedRange : seedRanges) {
        const auto soil = LookUp({ seedRange }, m_maps[0]);
        const auto fertilizer = LookUp(soil, m_maps[1]);
        const auto water = LookUp(fertilizer, m_maps[2]);
        const auto light = LookUp(water, m_maps[3]);
        const auto temperature = LookUp(light, m_maps[4]);
        const auto humidity = LookUp(temperature, m_maps[5]);
        const auto location = LookUp(humidity, m_maps[6]);
        globalMin = GetMin(globalMin, location);
    }

    return std::to_string(globalMin);
}

Day5::ull Day5::MapValue(mapping mapper, ull value) {
    for (auto rule : mapper) {
        if (value >= rule.sourceStart
            && value <= rule.sourceStart + rule.length) {
            ull offset = value - rule.sourceStart;
            return rule.destinationStart + offset;
        }
    }
    return value;
}

Day5::ull Day5::CalculateLocation(ull seed) {
    ull currentMin = ULLONG_MAX;
    auto value = seed;
    for (std::vector<mapping>::iterator it = m_maps.begin(); it != m_maps.end(); it++) {
        value = MapValue(*it, value);
    }
    currentMin = std::min(currentMin, value);
    return currentMin;
}

std::vector<Day5::pull> Day5::LookUp(std::vector<pull> keyRanges, mapping map) {
    std::vector<pull> results;
    for (const auto& keyRange : keyRanges) {
        ull minKey = keyRange.first;
        ull maxKey = minKey + keyRange.second - 1;

        std::vector<pull> usedRanges;
        for (const auto& rule : map) {
            ull minMapping = rule.sourceStart;
            ull maxMapping = rule.sourceStart + rule.length - 1;

            if (minMapping > maxKey || minKey > maxMapping)
                continue;

            ull minResult = std::max(minKey, minMapping);
            ull maxResult = std::min(maxKey, maxMapping);
            usedRanges.push_back({minResult, maxResult});
            ull range = maxResult - minResult + 1;

            ull delta = rule.destinationStart - rule.sourceStart;
            results.push_back({minResult + delta, range});
        }

        std::sort(usedRanges.begin(), usedRanges.end());
        ull start = minKey;
        for (const auto& usedRange : usedRanges) {
            if (start < usedRange.first)
                results.push_back({start, usedRange.first - start});

            start = usedRange.second + 1;
        }

        if (start <= maxKey)
            results.push_back({start, maxKey - start + 1});
    }

    return results;
}

Day5::ull Day5::GetMin(ull current, const std::vector<pull>& ranges) {
    ull ans = current;
    for (const auto& range : ranges)
        ans = std::min(ans, range.first);
    return ans;
}
