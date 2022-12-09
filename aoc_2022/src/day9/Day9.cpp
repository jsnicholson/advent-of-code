#include "Day9.h"

#include "Utils.hpp"

// up,down,left,right
const std::vector<Day9::coordinate> directions{ {0,1},{0,-1},{-1,0},{1,0} };

void Day9::Parse() {
    for (std::vector<std::string>::const_iterator it = data.begin(); it != data.end(); it++) {
        std::string line = *it;
        auto tokens = Utils::Split(line, ' ');
        char direction = tokens[0][0];
        int distance = std::stoi(tokens[1]);
        instruction instruction = std::make_pair(direction, distance);
        m_instructions.push_back(instruction);
    }
}

std::string Day9::Part1() {
    m_placesTailHasBeen.clear();
    coordinate headCoord(0, 0), tailCoord(0, 0);
    coordinate previousHeadCoord(0, 0);

    m_placesTailHasBeen.insert(tailCoord);
    for (std::vector<instruction>::const_iterator it = m_instructions.begin(); it != m_instructions.end(); it++) {
        auto direction = DirectionCommandToDirection(it->first);
        for (int count = 0; count < it->second; count++) {
            previousHeadCoord = headCoord;
            headCoord = headCoord + direction;
            if (!AreTwoCoordsTouching(headCoord, tailCoord)) {
                tailCoord = previousHeadCoord;
                m_placesTailHasBeen.insert(tailCoord);
            }
        }
    }

    return std::to_string(m_placesTailHasBeen.size());
}

std::string Day9::Part2() {
    m_placesTailHasBeen.clear();
    std::vector<coordinate> knots(10, std::make_pair(0, 0));
    coordinate &headKnot = knots[0], &tailKnot = knots[knots.size() - 1];

    for (std::vector<instruction>::const_iterator it = m_instructions.begin(); it != m_instructions.end(); it++) {
        auto direction = DirectionCommandToDirection(it->first);
        for (int count = 0; count < it->second; count++) {
            headKnot = headKnot + direction;
            for (int knot = 1; knot < knots.size(); knot++) {
                if (!AreTwoCoordsTouching(knots[knot - 1], knots[knot]))
                    MoveCoordTowards(knots[knot], knots[knot - 1]);
            }
            m_placesTailHasBeen.insert(tailKnot);
        }
    }
    return std::to_string(m_placesTailHasBeen.size());
}

bool Day9::AreTwoCoordsTouching(const coordinate firstCoord, const coordinate secondCoord) {
    auto difference = firstCoord - secondCoord;
    return (abs(difference.first) <= 1 && abs(difference.second) <= 1);
}

Day9::coordinate Day9::DirectionCommandToDirection(char command) {
    switch (command) {
    case 'U':
        return directions[0];
        break;
    case 'D':
        return directions[1];
        break;
    case 'L':
        return directions[2];
        break;
    case 'R':
        return directions[3];
        break;
    }
    EXIT_FAILURE;
    return std::make_pair(INT_MIN,INT_MIN);
}

void Day9::MoveCoordTowards(coordinate& coord, const coordinate towards) {
    auto difference = towards - coord;
    if (difference.first < 0)
        coord.first -= 1;
    else if (difference.first > 0)
        coord.first += 1;
    if (difference.second < 0)
        coord.second -= 1;
    else if (difference.second > 0)
        coord.second += 1;
}

std::pair<int, int> operator+(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
    return std::make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}

std::pair<int, int> operator-(const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) {
    return std::make_pair(lhs.first - rhs.first, lhs.second - rhs.second);
}