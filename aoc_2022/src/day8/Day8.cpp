#include "Day8.h"

#include <iostream>

void Day8::Parse() {
    for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        std::string line = *it;
        std::vector<int> row{};
        for (std::string::iterator stringIt = line.begin(); stringIt != line.end(); stringIt++)
            row.push_back(*stringIt - '0');
        m_trees.push_back(row);
    }
}

std::string Day8::Part1() {
    std::vector<std::vector<int>> trees = m_trees;
    // have to do int instead of bool as std::vector<bool> is weird af (https://stackoverflow.com/a/63477526)
    std::vector<std::vector<int>> whichTreesVisibleFromOutsideGrid(trees.size(), std::vector<int>(m_trees.size(), false));

    for (int direction = 0; direction < 4; direction++) {
        CalculateVisibilityFromLeft(trees, whichTreesVisibleFromOutsideGrid);
        Rotate(trees);
        Rotate(whichTreesVisibleFromOutsideGrid);
    }
    
    int count = 0;
    for (int row = 0; row < whichTreesVisibleFromOutsideGrid.size(); row++) {
        count += std::count(whichTreesVisibleFromOutsideGrid[row].begin(), whichTreesVisibleFromOutsideGrid[row].end(), true);
    }

    return std::to_string(count);
}

std::string Day8::Part2() {
    return std::string("unimplemented");
}

void Day8::CalculateVisibilityFromLeft(const std::vector<std::vector<int>>& trees, std::vector<std::vector<int>>& visibility) {
    int gridSize = trees.size();
    for (int row = 0; row < gridSize; row++) {
        int currentMax = -1;
        for (int column = 0; column < gridSize; column++) {
            if (trees[row][column] > currentMax && !visibility[row][column]) {
                visibility[row][column] = true;
            }
            currentMax = std::max(currentMax, trees[row][column]);
        }
    }
}

void Day8::Rotate(std::vector<std::vector<int>>& matrix) {
    std::reverse(matrix.begin(), matrix.end());
    for (int row = 0; row < matrix.size(); row++) {
        for (int column = row + 1; column < matrix[row].size(); ++column) {
            std::swap(matrix[row][column], matrix[column][row]);
        }
    }
}