#include "Day12.h"

#include <algorithm>

// directions l,u,r,d
const std::vector<std::pair<int, int>> directions{ {-1,0},{0,1},{1,0},{0,-1} };

void Day12::Parse() {
    m_gridSize = std::make_pair(data[0].size(), data.size());
    size_t x, y;
    for (y = 0; y < m_gridSize.second; y++) {
        for (x = 0; x < m_gridSize.first; x++) {
            coordinate coord = std::make_pair(x, y);
            CheckForStartAndEnd(coord);
            nodename name = CoordToName(coord);
            edges edges = GetNeighbours(coord);

            m_graph.insert(std::make_pair(name,edges));
        }
    }
}

std::string Day12::Part1() {
    return std::string("unimplemented");
}

std::string Day12::Part2() {
    return std::string("unimplemented");
}

Day12::nodename Day12::CoordToName(coordinate coord) {
    std::string name;
    name.append(std::to_string(coord.first)); name += ','; name.append(std::to_string(coord.second)); name += ':'; name += GetValue(coord);
    return name;
}

void Day12::CheckForStartAndEnd(Day12::coordinate coord) {
    auto value = data[coord.second][coord.first];
    if (value == 'S')
        m_start = coord;
    else if (value == 'E')
        m_end = coord;
}

char Day12::GetValue(Day12::coordinate coord) {
    char value = data[coord.second][coord.first];
    if (value == 'S')
        value = 'a';
    else if (value == 'E')
        value = 'z';
    return value;
}

std::vector<Day12::nodename> Day12::GetNeighbours(coordinate coord) {
    std::vector<nodename> neighbours{};
    auto value = GetValue(coord);
    for (const auto& direction : directions) {
        coordinate neighbourCoord = std::make_pair(coord.first + direction.first, coord.second + direction.second);
        if (!IsCoordinateInGrid(neighbourCoord, m_gridSize))
            continue;
        auto neighbourValue = data[neighbourCoord.second][neighbourCoord.first];
        if (IsValidNeighbour(value, neighbourValue))
            neighbours.push_back(CoordToName(neighbourCoord));
    }
    return neighbours;
}

bool Day12::IsCoordinateInGrid(Day12::coordinate coord, Day12::coordinate gridSize) {
    return (coord.first >= 0 && coord.first < gridSize.first) &&
        (coord.second >= 0 && coord.second < gridSize.second);
}

bool Day12::IsValidNeighbour(int value, int neighbourValue) {
    return neighbourValue < value + 1;
}