#include "Day12.h"

#include <algorithm>
#include <queue>
#include <iostream>

// directions l,u,r,d
const std::vector<std::pair<int, int>> directions{ {-1,0},{0,-1},{1,0},{0,1} };

void Day12::Parse() {
    m_gridSize = std::make_pair(data[0].size(), data.size());
    m_gridSizeFlat = m_gridSize.first * m_gridSize.second;

    FindAndReplaceStartAndEnd();

    size_t x, y;
    for (y = 0; y < m_gridSize.second; y++) {
        for (x = 0; x < m_gridSize.first; x++) {
            coordinate coord = std::make_pair(x, y);
            nodename name = FlattenCoordinate(coord);
            edges edges = GetNeighbours(coord);

            m_graph.insert(std::make_pair(name,edges));
        }
    }
}

std::string Day12::Part1() {
    auto distance = FewestSteps(m_start, m_end);
    return std::to_string(distance);
}

std::string Day12::Part2() {
    auto lowestPoints = FindPointsOfLowestElevation();
    int fewestSteps = INT_MAX;
    for (const auto& lowPoint : lowestPoints) {
        auto distance = FewestSteps(lowPoint, m_end);
        fewestSteps = std::min(fewestSteps, distance);
    }
    return std::to_string(fewestSteps);
}

void Day12::FindAndReplaceStartAndEnd() {
    for (int y = 0; y < m_gridSize.second; y++) {
        for (int x = 0; x < m_gridSize.first; x++) {
            coordinate coord = std::make_pair(x, y);
            if (GetValue(coord) == 'S') {
                m_start = FlattenCoordinate(coord);
                data[y][x] = 'a';
            }
            else if (GetValue(coord) == 'E') {
                m_end = FlattenCoordinate(coord);
                data[y][x] = 'z';
            }
        }
    }

    if (m_start == INT_MIN || m_end == INT_MIN) {
        std::cout << "input does not contain start and end" << std::endl;
        EXIT_FAILURE;
    }
}

char Day12::GetValue(Day12::coordinate coord) {
    return data[coord.second][coord.first];
}

char Day12::GetValueWithFlatIndex(size_t flatIndex) {
    return GetValue(FlatIndexToCoordinate(flatIndex));
}

std::vector<Day12::nodename> Day12::GetNeighbours(coordinate coord) {
    std::vector<nodename> neighbours{};
    auto value = GetValue(coord);
    if (value == 'x') {
        auto something = 1;
    }
    for (const auto& direction : directions) {
        coordinate neighbourCoord = std::make_pair(coord.first + direction.first, coord.second + direction.second);
        if (!IsCoordinateInGrid(neighbourCoord, m_gridSize))
            continue;
        auto neighbourValue = data[neighbourCoord.second][neighbourCoord.first];
        if (IsValidNeighbour(value, neighbourValue))
            neighbours.push_back(FlattenCoordinate(neighbourCoord));
    }
    return neighbours;
}

bool Day12::IsCoordinateInGrid(Day12::coordinate coord, Day12::coordinate gridSize) {
    return (coord.first >= 0 && coord.first < gridSize.first) &&
        (coord.second >= 0 && coord.second < gridSize.second);
}

bool Day12::IsValidNeighbour(int value, int neighbourValue) {
    return neighbourValue <= value + 1;
}

size_t Day12::FlattenCoordinate(Day12::coordinate coord) {
    return (coord.second * m_gridSize.first) + coord.first;
}

Day12::coordinate Day12::FlatIndexToCoordinate(size_t flatIndex) {
    return std::make_pair(flatIndex / m_gridSize.first, flatIndex % m_gridSize.first);
}

int Day12::FewestSteps(Day12::nodename start, Day12::nodename end) {
    std::vector<int> distances(m_gridSizeFlat, INT_MAX);
    std::vector<nodename> previousNode(m_gridSizeFlat, INT_MIN);
    std::queue<nodename> nodes;
    distances[start] = 0;
    nodes.push(start);
    while (nodes.size() > 0) {
        auto node = nodes.front();
        nodes.pop();
        auto neighbours = m_graph.at(node);
        for (const auto& neighbour : neighbours) {
            if (distances[neighbour] == INT_MAX) {
                distances[neighbour] = distances[node] + 1;
                previousNode[neighbour] = node;
                nodes.push(neighbour);
            }
        }
    }

    return distances[end];
}

std::vector<Day12::nodename> Day12::FindPointsOfLowestElevation() {
    std::vector<nodename> lowestPoints;
    for (int y = 0; y < m_gridSize.second; y++) {
        for (int x = 0; x < m_gridSize.first; x++) {
            coordinate coord = std::make_pair(x, y);
            if (GetValue(coord) == 'a') {
                lowestPoints.push_back(FlattenCoordinate(coord));
            }
        }
    }
    return lowestPoints;
}