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
    coord currentCoord = m_startCoord;
    char currentPipe;
    coord lastDirection = {};
    std::vector<coord> vecCoordsPartOfLoop = {};
    do {
        currentPipe = m_grid[currentCoord.second][currentCoord.first];
        std::vector<coord> validDirections = mapPipeToDirections.at(currentPipe);
        std::vector<coord>::iterator it = std::find(validDirections.begin(), validDirections.end(), lastDirection);
        if(it != validDirections.end())
            validDirections.erase(it);
        const std::pair<char, coord> foundConnectingNeighbour = FindConnectingNeighbour(currentCoord, validDirections);
        vecCoordsPartOfLoop.push_back(foundConnectingNeighbour.second);
        lastDirection = Utils::subtract(currentCoord, foundConnectingNeighbour.second);
        currentCoord = foundConnectingNeighbour.second;
    } while (currentCoord != m_startCoord);
    return std::to_string(((int)vecCoordsPartOfLoop.size()/2));
}

std::string Day10::Part2() {
    return std::to_string(0);
}

std::pair<char, Day10::coord> Day10::FindConnectingNeighbour(const coord& startingCoord, const std::vector<coord>& directions) {
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