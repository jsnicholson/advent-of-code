#include "Day11.h"

#include "Utils.hpp"

void Day11::Parse() {
    m_universe = data;
}

std::string Day11::Part1() {
    const universe expandedUniverse = CalculateExpandedUniverse(m_universe);
    std::cout << std::endl;
    for (const auto& line : expandedUniverse)
        std::cout << line << std::endl;
    std::cout << std::endl;
    return std::to_string(0);
}

std::string Day11::Part2() {
    return std::to_string(0);
}

int Day11::CalculateShortestDiscreteDistanceBetweenPoints(const coord& a, const coord& b) {
    return 0;
}

Day11::universe Day11::CalculateExpandedUniverse(const universe& originalUniverse) {
    universe expandedUniverse = originalUniverse;
    const auto emptyColumns = GetIndicesOfEmptyColumns(expandedUniverse);
    const auto emptyRows = GetIndicesOfEmptyRows(expandedUniverse);
    AddColumnsToUniverse(expandedUniverse, emptyColumns);
    AddRowsToUniverse(expandedUniverse, emptyRows);
    return expandedUniverse;
}

void Day11::AddRowsToUniverse(universe& universe, std::vector<size_t> rowIndices) {
    for (std::vector<size_t>::iterator it = rowIndices.begin(); it != rowIndices.end(); it++)
        *it += std::distance(rowIndices.begin(), it);

    size_t rowLength = universe[0].size();
    for (const auto& rowIndex : rowIndices)
        universe.insert(universe.begin() + rowIndex, std::string(rowLength,'.'));
}

void Day11::AddColumnsToUniverse(universe& universe, std::vector<size_t> columnIndices) {
    for (std::vector<size_t>::iterator it = columnIndices.begin(); it != columnIndices.end(); it++)
        *it += std::distance(columnIndices.begin(), it);

    size_t columnLength = universe.size();
    for (auto& row : universe) {
        for (const auto& columnIndex : columnIndices)
            row.insert(columnIndex, 1,'.');
    }
}

std::vector<size_t> Day11::GetIndicesOfEmptyRows(const universe& universe) {
    std::vector<size_t> vecEmptyRows = {};
    for (std::vector<std::string>::const_iterator it = universe.begin(); it != universe.end(); it++) {
        if (it->find_first_not_of('.') == std::string::npos)
            vecEmptyRows.push_back(std::distance(universe.begin(),it));

    }
    return vecEmptyRows;
}

std::vector<size_t> Day11::GetIndicesOfEmptyColumns(const universe& universe) {
    std::vector<size_t> vecEmptyColumnCandidates(universe.size());
    std::iota(vecEmptyColumnCandidates.begin(), vecEmptyColumnCandidates.end(), 0);
    for (std::vector<std::string>::const_iterator universeIterator = universe.begin(); universeIterator != universe.end(); universeIterator++) {
        std::erase_if(vecEmptyColumnCandidates, 
            [universeIterator](const auto& i) {
                return (*universeIterator)[i] == '#';
            });
    }
    return vecEmptyColumnCandidates;
}