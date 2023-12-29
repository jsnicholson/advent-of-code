#include "Day10.h"

#include "Utils.hpp"

void Day10::Parse() {
    m_grid = data;

    for (std::vector<std::string>::iterator it = m_grid.begin(); it != m_grid.end(); it++) {
        std::string line = *it;
        size_t found = line.find('S');
        if (found != std::string::npos) {
            m_startCoord = std::make_pair(found,std::distance(m_grid.begin(),it));
            break;
        }
    }
}

std::string Day10::Part1() {
    std::vector<coord> vecCoordsPartOfLoop = CalculateLoop(m_startCoord);
    return std::to_string(((int)vecCoordsPartOfLoop.size()/2));
}

std::string Day10::Part2() {
    return std::to_string(0);
}

std::vector<Day10::coord> Day10::CalculateLoop(const coord& startCoord) {
    coord currentCoord = startCoord;
    direction lastDirection = {};
    std::vector<coord> vecCoordsPartOfLoop = {};
    do {
        std::vector<direction> validDirections = GetValidDirections(currentCoord, lastDirection);
        const std::pair<char, coord> foundConnectingNeighbour = FindConnectingNeighbour(currentCoord, validDirections);
        vecCoordsPartOfLoop.push_back(foundConnectingNeighbour.second);
        lastDirection = Utils::subtract(currentCoord, foundConnectingNeighbour.second);
        currentCoord = foundConnectingNeighbour.second;
    } while (currentCoord != m_startCoord);
    return vecCoordsPartOfLoop;
}

std::vector<Day10::direction> Day10::GetValidDirections(const coord& fromCoord, const direction& lastDirection) {
    char currentPipe = m_grid[fromCoord.second][fromCoord.first];
    std::vector<direction> validDirections = mapPipeToDirections.at(currentPipe);
    std::vector<direction>::iterator it = std::find(validDirections.begin(), validDirections.end(), lastDirection);
    if (it != validDirections.end())
        validDirections.erase(it);
    return validDirections;
}

std::pair<char, Day10::coord> Day10::FindConnectingNeighbour(const coord& startingCoord, const std::vector<direction>& directions) {
    for (const auto& direction : directions) {
        coord coordToCheck = Utils::add(startingCoord, direction);
        char foundPipe = m_grid[coordToCheck.second][coordToCheck.first];
        if (mapDirectionToPipes.find(direction) == mapDirectionToPipes.end())
            continue;
        std::vector<char> validPipes = mapDirectionToPipes.at(direction);
        if (Utils::contains(validPipes,foundPipe))
            return std::make_pair(foundPipe, coordToCheck);
    }

    return std::make_pair(NULL,none);
}

int Day10::ShoeLace(const std::vector<coord>& path) {
    if (path.size() <= 1) {
        return 0;
    }

    int result = 0;
    for (size_t i = 0; i < path.size() - 1; ++i) {
        int x1 = path[i].first;
        int y1 = path[i].second;
        int x2 = path[i + 1].first;
        int y2 = path[i + 1].second;

        result += (y1 + y2) * (x2 - x1);
    }

    return result;
}