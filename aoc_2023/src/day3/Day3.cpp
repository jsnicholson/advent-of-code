#include "Day3.h"
#include "Utils.hpp"

#include <regex>
#include <set>

void Day3::Parse() {
    m_grid = data;
    m_schematic = std::accumulate(m_grid.begin(), m_grid.end(), std::string{});
    int gridX = m_grid[0].length();
    int gridY = m_grid.size();
    m_indexNeighbours[0] = -gridX - 1;
    m_indexNeighbours[1] = -gridX;
    m_indexNeighbours[2] = -gridX + 1;
    m_indexNeighbours[3] = -1;
    m_indexNeighbours[4] = +1;
    m_indexNeighbours[5] = gridX - 1;
    m_indexNeighbours[6] = gridX;
    m_indexNeighbours[7] = gridX + 1;

    std::regex regexNumber = std::regex("[0-9]+");
    for (std::sregex_iterator i = std::sregex_iterator(m_schematic.begin(), m_schematic.end(), regexNumber); i != std::sregex_iterator(); ++i) {
        std::smatch match = *i;
        for (int i = 0; i < match.length(); i++) {
            int position = match.position() + i;
            int value = std::stoi(match.str());
            int id = match.position();
            m_mapPartNumbers[position] = part(id,value);
        }
    }
}

std::string Day3::Part1() {
    std::regex regexSymbol = std::regex("[^a-zA-Z0-9.\s]");
    std::set<int> setPartNumberIds;
    std::vector<int> vectorPartNumberValues;
    for (std::sregex_iterator i = std::sregex_iterator(m_schematic.begin(), m_schematic.end(), regexSymbol); i != std::sregex_iterator(); ++i) {
        std::smatch match = *i;
        for (int neighbourIndex : m_indexNeighbours) {
            std::map<int, part>::iterator itPartAtLocation = m_mapPartNumbers.find(match.position() + neighbourIndex);
            
            if (itPartAtLocation != m_mapPartNumbers.end()
                && !setPartNumberIds.contains(itPartAtLocation->second.id)) {
                setPartNumberIds.insert(itPartAtLocation->second.id);
                vectorPartNumberValues.push_back(itPartAtLocation->second.value);
            }
        }
    }
    return std::to_string(std::accumulate(vectorPartNumberValues.begin(), vectorPartNumberValues.end(), 0));
}

std::string Day3::Part2() {
    return std::to_string(0);
}