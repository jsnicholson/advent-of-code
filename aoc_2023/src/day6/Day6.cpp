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

    for (ull i = 0; i < timeTokens.size(); i++) {
        race r = {
            std::stoi(timeTokens[i]),
            std::stoi(distanceTokens[i])
        };
        m_races.push_back(r);
    }
}

std::string Day6::Part1() {
    ull total = 1;
    for (const auto& race : m_races) {
        auto intersections = SolveForTime(race.length, race.distance);
        total *= std::ceil(intersections.second) - std::floor(intersections.first) - 1;
    }
    return std::to_string(total);
}

std::string Day6::Part2() {
    race race = ConcatenateRaces();
    return std::to_string(CalculateWaysToBeat(race));
}

Day6::ull Day6::SolveForDistance(ull raceLength, ull timeButtonHeld) {
    return (raceLength - timeButtonHeld) * timeButtonHeld;
}

std::pair<double, double> Day6::SolveForTime(ull raceLength, ull raceDistance) {
    std::pair<double, double> timesButtonHeld;
    timesButtonHeld.first = (raceLength - std::sqrt(raceLength * raceLength - 4 * raceDistance)) / 2;
    timesButtonHeld.second = (raceLength + std::sqrt(raceLength * raceLength - 4 * raceDistance)) / 2;
    return timesButtonHeld;
}

Day6::ull Day6::CalculateWaysToBeat(race race) {
    auto intersections = SolveForTime(race.length, race.distance);
    return std::ceil(intersections.second) - std::floor(intersections.first) - 1;
}

Day6::race Day6::ConcatenateRaces() {
    std::string raceLength;
    std::string bestDistance;
    for (const auto& race : m_races) {
        raceLength += std::to_string(race.length);
        bestDistance += std::to_string(race.distance);
    }

    return race{
        std::stoull(raceLength,nullptr),
        std::stoull(bestDistance,nullptr)
    };
}