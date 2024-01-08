#include "Day11.h"

#include "Utils.hpp"

#include <format>

void Day11::Parse() {
    m_universe = data;
}

std::string Day11::Part1() {
    const universe expandedUniverse = CalculateExpandedUniverse(m_universe, m_expansionPart1);
    const std::vector<coord> galaxyCoords = FindAllGalaxies(expandedUniverse);
    int64_t total = 0;

    for (int i = 0; i < galaxyCoords.size(); i++) {
        for (int j = 0; j < galaxyCoords.size(); j++) {
            if (i == j)
                continue;
            total += CalculateShortestDiscreteDistanceBetweenPoints(galaxyCoords[i], galaxyCoords[j]);
        }
    }
    return std::to_string(total/2);
}

std::string Day11::Part2() {
    const std::vector<size_t> vecEmptyRows = GetIndicesOfEmptyRows(m_universe);
    const std::vector<size_t> vecEmptyColumns = GetIndicesOfEmptyColumns(m_universe);
    const std::vector<coord> galaxyCoords = FindAllGalaxies(m_universe);
    std::vector<coord> expandedGalaxyCoords = {};
    for (const auto& galaxy : galaxyCoords) {
        coord displacement = CalculateDisplacementAfterExpansion(vecEmptyRows, vecEmptyColumns, galaxy);
        displacement = Utils::multiply<int64_t>(displacement, m_expansionPart2 - 1);
        expandedGalaxyCoords.push_back(Utils::add(galaxy, displacement));
    }

    int64_t total = 0;
    for (int i = 0; i < expandedGalaxyCoords.size(); i++) {
        for (int j = 0; j < expandedGalaxyCoords.size(); j++) {
            if (i == j)
                continue;
            total += CalculateShortestDiscreteDistanceBetweenPoints(expandedGalaxyCoords[i], expandedGalaxyCoords[j]);
        }
    }
    return std::to_string(total/2);
}

int Day11::CalculateShortestDiscreteDistanceBetweenPoints(const coord& a, const coord& b) {
    return std::abs(a.first - b.first) + std::abs(a.second - b.second);
}

Day11::universe Day11::CalculateExpandedUniverse(const universe& originalUniverse, const int expansion) {
    universe expandedUniverse = originalUniverse;
    const auto emptyColumns = GetIndicesOfEmptyColumns(expandedUniverse);
    const auto emptyRows = GetIndicesOfEmptyRows(expandedUniverse);
    AddColumnsToUniverse(expandedUniverse, emptyColumns, expansion);
    AddRowsToUniverse(expandedUniverse, emptyRows, expansion);
    return expandedUniverse;
}

void Day11::AddRowsToUniverse(universe& universe, std::vector<size_t> rowIndices, const int expansion) {
    int displacement = expansion - 1;
    for (std::vector<size_t>::iterator it = rowIndices.begin(); it != rowIndices.end(); it++)
        *it += std::distance(rowIndices.begin(), it)*displacement;

    size_t rowLength = universe[0].size();
    for (const auto& rowIndex : rowIndices)
        for(int i = 0; i < displacement; i++)
        universe.insert(universe.begin() + rowIndex, std::string(rowLength,'.'));
}

void Day11::AddColumnsToUniverse(universe& universe, std::vector<size_t> columnIndices, const int expansion) {
    int displacement = expansion - 1;
    for (std::vector<size_t>::iterator it = columnIndices.begin(); it != columnIndices.end(); it++)
        *it += std::distance(columnIndices.begin(), it)*displacement;

    size_t columnLength = universe.size();
    for (auto& row : universe) {
        for (const auto& columnIndex : columnIndices)
            row.insert(columnIndex, displacement,'.');
    }
}

std::vector<size_t> Day11::GetIndicesOfEmptyRows(const universe& universe) {
    std::vector<size_t> vecEmptyRows = {};
    for (universe::const_iterator it = universe.begin(); it != universe.end(); it++) {
        if (it->find_first_not_of('.') == std::string::npos)
            vecEmptyRows.push_back(std::distance(universe.begin(),it));

    }
    return vecEmptyRows;
}

std::vector<size_t> Day11::GetIndicesOfEmptyColumns(const universe& universe) {
    std::vector<size_t> vecEmptyColumnCandidates(universe.size());
    std::iota(vecEmptyColumnCandidates.begin(), vecEmptyColumnCandidates.end(), 0);
    for (universe::const_iterator universeIterator = universe.begin(); universeIterator != universe.end(); universeIterator++) {
        std::erase_if(vecEmptyColumnCandidates, 
            [universeIterator](const auto& i) {
                return (*universeIterator)[i] == '#';
            });
    }
    return vecEmptyColumnCandidates;
}

std::vector<Day11::coord> Day11::FindAllGalaxies(const universe& universe) {
    std::vector<coord> vecGalaxyCoords = {};
    for (universe::const_iterator it = universe.begin(); it != universe.end(); it++) {
        size_t rowIndex = std::distance(universe.begin(),it);
        auto b = Utils::FindAll(*it, '#');
        for(auto i : b)
            vecGalaxyCoords.push_back(std::make_pair(rowIndex,i));
    }
    return vecGalaxyCoords;
}

Day11::coord Day11::CalculateDisplacementAfterExpansion(const std::vector<size_t>& vecEmptyRows, const std::vector<size_t>& vecEmptyColumns, const coord& point){
    coord result;
    result.first = std::count_if(vecEmptyRows.begin(), vecEmptyRows.end(),
        [point](const size_t i) {
            return i < point.first;
        });
    result.second = std::count_if(vecEmptyColumns.begin(), vecEmptyColumns.end(),
        [point](const size_t i) {
            return i < point.second;
        });
    return result;
}