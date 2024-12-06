#include "Day4.h"

#include "Utils.hpp"

void Day4::Parse() {
    int rows = data[0].size(), cols = data.size();

    // add horizontal
    m_allPossibleLines = data;

    // add vertical
    for (size_t j = 0; j < cols; j++) {
        std::string line;
        for (size_t i = 0; i < rows; i++) {
            line += data[i][j];
        }
        m_allPossibleLines.push_back(line);
    }

    // add diagonal (top-left to bottom-right)
    for (size_t start = 0; start < rows + cols - 1; ++start) {
        std::string diagonal;
        for (size_t i = 0; i <= start; ++i) {
            size_t row = i;
            size_t col = start - i;
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
    int count = 0, rows = data[0].size(), cols = data.size();

    for (size_t row = 1; row < rows - 1; row++) {
        for (size_t col = 1; col < cols - 1; col++) {
            std::pair<size_t, size_t> centrePos = std::make_pair(row, col), topleftPos = Utils::add(centrePos, Utils::TOPLEFT), toprightPos = Utils::add(centrePos, Utils::TOPRIGHT), bottomrightPos = Utils::add(centrePos, Utils::BOTTOMRIGHT), bottomleftPos = Utils::add(centrePos, Utils::BOTTOMLEFT);
            char centre = Utils::ElementAt(data, centrePos), topleft = Utils::ElementAt(data, topleftPos), topright = Utils::ElementAt(data, toprightPos), bottomright = Utils::ElementAt(data, bottomrightPos), bottomleft = Utils::ElementAt(data, bottomleftPos);

            std::string tlbr = std::string() + topleft + centre + bottomright;
            std::string trbl = std::string() + topright + centre + bottomleft;

            if ((tlbr == "MAS" || tlbr == "SAM")
                && (trbl == "MAS" || trbl == "SAM")) count++;
        }
    }

    return std::to_string(count);
}