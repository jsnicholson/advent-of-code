#include "Day10.h"

void Day10::Parse() {
    m_grid = data;

    for (std::vector<std::string>::iterator it = m_grid.begin(); it != m_grid.end(); it++) {
        std::string line = *it;
        size_t found = line.find('S');
        if (found != std::string::npos) {
            m_startCoord = std::make_pair(std::distance(m_grid.begin(),it),found);
            break;
        }
    }
}

std::string Day10::Part1() {
    return std::to_string(0);
}

std::string Day10::Part2() {
    return std::to_string(0);
}