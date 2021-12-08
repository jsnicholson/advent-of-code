#include "Day4.h"

#include <iostream>
#include <iterator>
#include <sstream>

#include "Utils.hpp"

void Day4::Parse() {
    board tempBoard;
    for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        if (it == data.begin()) {
            Utils::SplitStringIntoVector(vectorBingoNumbers, *it, ',');
            continue;
        }

        if (it->empty()) {
            continue;
        } else {
            std::vector<std::pair<int, bool>> tempLine;
            std::istringstream iss(*it);
            std::string item;
            while (std::getline(iss, item, ' ')) {
                if (item.empty())
                    continue;
                tempLine.push_back(std::make_pair(std::stoi(item), false));
            }
            tempBoard.push_back(tempLine);

            if (tempBoard.size() == tempBoard.front().size()) {
                if (boardDimension < 1)
                    boardDimension = tempBoard.size();

                vectorBoards.push_back(tempBoard);
                tempBoard.clear();
            }
        }
    }
}

int Day4::Part1() {
    int result = -1;
    for (std::vector<int>::iterator it = vectorBingoNumbers.begin(); it != vectorBingoNumbers.end(); it++) {
        MarkNumbers(*it);
        if ((result = CheckForWin(*it)) != -1) {
            std::cout << "Won on number:" << *it << std::endl;
            break;
        }
    }
    return result;
}

int Day4::Part2() {
    return -1;
}

void Day4::MarkNumbers(int num) {
    for (int i = 0; i < vectorBoards.size(); i++) {
        //for each board
        board& board = vectorBoards[i];
        for (auto& line : board) {
            for (auto& item : line) {
                if (item.first == num)
                    item.second = true;
            }
        }
    }
}

int Day4::CheckForWin(int num) {
    bool win = false;
    for (const auto& board : vectorBoards) {
        // check for horizontal
        for (const auto& line : board) {
            int lineSum = 0;
            bool win = false;
            for (const auto& entry : line) {
                if (entry.second) {
                    lineSum += entry.first;
                    win = true;
                } else {
                    win = false;
                    break;
                }
            }

            if (win) {
                return Utils::SumUnmarkedBoard(board) * num;
            }
        }

        // check for vertical
        for (int col = 0; col < boardDimension; col++) {
            int lineSum = 0;
            bool win = false;
            for (const auto& line : board) {
                const auto& entry = line[col];
                if (entry.second) {
                    lineSum += entry.first;
                    win = true;
                } else {
                    win = false;
                    break;
                }
            }

            if (win) {

                return Utils::SumUnmarkedBoard(board) * num;
            }
        }
    }
    return -1;
}