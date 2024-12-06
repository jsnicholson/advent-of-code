#include "Day4.h"

#include "Utils.hpp"

void Day4::Parse() {
    int rows = data[0].size(), cols = data.size();

    // add horizontal
    m_allPossibleLines = data;

    // add vertical
    for (int j = 0; j < cols; j++) {
        std::string line;
        for (int i = 0; i < rows; i++) {
            line += data[i][j];
        }
        m_allPossibleLines.push_back(line);
    }

    // add diagonal (top-left to bottom-right)
    for (int start = 0; start < rows + cols - 1; ++start) {
        std::string diagonal;
        for (int i = 0; i <= start; ++i) {
            int row = i;
            int col = start - i;
            if (row < rows && col < cols) {
                diagonal += data[row][col];
            }
        }
        if (!diagonal.empty()) {
            m_allPossibleLines.push_back(diagonal);
        }
    }

    // add diagonals (top-right to bottom-left)
    for (int start = 0; start < rows + cols - 1; ++start) {
        std::string diagonal;
        for (int i = 0; i <= start; ++i) {
            int row = i;
            int col = cols - 1 - (start - i);
            if (row < rows && col >= 0) {
                diagonal += data[row][col];
            }
        }
        if (!diagonal.empty()) {
            m_allPossibleLines.push_back(diagonal);
        }
    }
}

std::string Day4::Part1() {
    int count = 0;

    for (const auto& line : m_allPossibleLines) {
        count += Utils::CountOfSubstringInString(line, Day4::WORD);
        count += Utils::CountOfSubstringInString(line, std::string(Day4::WORD.rbegin(), Day4::WORD.rend()));
    }

    return std::to_string(count);
}

std::string Day4::Part2() {
    return std::string("unimplemented");
}