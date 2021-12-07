#include "Day4.h"

#include <iostream>

#include "Utils.hpp""

void Day4::Parse() {
    std::vector<std::vector<int>> board;

    for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++) {

        // line 1 is called numbers
        if (it == data.begin()) {
            Utils::SplitStringIntoVector(vectorBingoNumbers, *it, ',');
            continue;
        }

        if (it->empty()) {
            board.clear();
            continue;
        } else {
            std::vector<int> line;
            Utils::SplitStringIntoVector(line, *it, ' ');

            //push horizontal line
            vectorWinningLines.push_back(line);

            // save to board to get vertical lines later
            board.push_back(line);

            if (board.size() == board.front().size())
                BoardToVerticalWinningLines(board);
        }    
    }
}

int Day4::Part1() {
    return -1;
}

int Day4::Part2() {
    return -1;
}

void Day4::BoardToVerticalWinningLines(std::vector<std::vector<int>>& board) {
    std::vector<int> tempWinningLine;
    for (int i = 0; i < board.front().size(); i++) {
        tempWinningLine.clear();

        for (const auto& line : board) {
            tempWinningLine.push_back(line[i]);
        }

        vectorWinningLines.push_back(tempWinningLine);
    }
}