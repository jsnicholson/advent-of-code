#include "Day6.h"

#include "Utils.hpp"
#include <format>

void Day6::Parse() {
    std::string times = data[0];
    auto timeTokens = Utils::Split(times, ' ');
    std::erase_if(timeTokens, [](const auto& s) {
        return s.length() == 0;
        });
    timeTokens.erase(timeTokens.begin());

    std::string distances = data[1];
    auto distanceTokens = Utils::Split(distances, ' ');
    std::erase_if(distanceTokens, [](const auto& s) {
        return s.length() == 0;
        });
    distanceTokens.erase(distanceTokens.begin());

    for (int i = 0; i < timeTokens.size(); i++) {
        race r = {
            std::stoi(distanceTokens[i]),
            std::stoi(timeTokens[i])
        };
        m_races.push_back(r);
    }
}

std::string Day6::Part1() {
    int total = 1;
    for (const auto& race : m_races) {
        auto intersections = SolveForTime(race.length, race.distance);
        int waysToBeat = std::ceil(intersections.second) - std::floor(intersections.first) - 1;
        total *= waysToBeat;
    }
    return std::to_string(total);
}

std::string Day6::Part2() {
    return std::to_string(0);
}

int Day6::SolveForDistance(int raceLength, int timeButtonHeld) {
    return (raceLength - timeButtonHeld) * timeButtonHeld;
}

std::pair<double, double> Day6::SolveForTime(int raceLength, int raceDistance) {
    std::pair<double, double> timesButtonHeld;
    timesButtonHeld.first = (raceLength - std::sqrt(raceLength * raceLength - 4 * raceDistance)) / 2;
    timesButtonHeld.second = (raceLength + std::sqrt(raceLength * raceLength - 4 * raceDistance)) / 2;
    return timesButtonHeld;
}