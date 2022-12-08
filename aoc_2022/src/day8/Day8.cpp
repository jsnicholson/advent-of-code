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
    std::vector<std::vector<int>> whichTreesVisibleFromOutsideGrid(trees.size(), std::vector<int>(trees.size(), false));

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
    std::vector<std::vector<int>> trees = m_trees;
    std::vector<std::vector<int>> treeScenicScores(trees.size(), std::vector<int>(trees.size(), 0));

    int maxScenicScore = 0;
    for (int row = 1; row < trees.size() - 1; row++) {
        for (int column = 1; column < trees.size(); column++) {
            maxScenicScore = std::max(maxScenicScore, CalculateScenicScore(trees,std::make_pair(row,column)));
        }
    }

    return std::to_string(maxScenicScore);
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

int Day8::CalculateScenicScore(const std::vector<std::vector<int>>& trees, std::pair<int,int> tree) {
    int height = trees[tree.first][tree.second];
    std::vector<std::pair<int, int>> directions{ {0,-1},{0,1},{-1,0},{1,0} };
    std::pair<int, int> minCoord(0, 0);
    std::pair<int, int> maxCoord(trees.size() - 1, trees.size() - 1);
    int totalScenicScore = 1;
    for (const auto& direction : directions) {
        int directionScenicScore = 0;
        std::pair<int, int> coord = std::make_pair(tree.first+direction.first,tree.second+direction.second);
        while (PairInRange(minCoord, maxCoord, coord)) {
            directionScenicScore++;
            if (trees[coord.first][coord.second] >= height)
                break;
            coord.first += direction.first;
            coord.second += direction.second;
        }
        totalScenicScore *= directionScenicScore;
    }
    return totalScenicScore;
}

void Day8::Rotate(std::vector<std::vector<int>>& matrix) {
    std::reverse(matrix.begin(), matrix.end());
    for (int row = 0; row < matrix.size(); row++) {
        for (int column = row + 1; column < matrix[row].size(); ++column) {
            std::swap(matrix[row][column], matrix[column][row]);
        }
    }
}

bool Day8::PairInRange(std::pair<int, int> min, std::pair<int, int> max, std::pair<int, int> value) {
    return (value.first >= min.first && value.first <= max.first) &&
        (value.second >= min.second && value.second <= max.second);
}