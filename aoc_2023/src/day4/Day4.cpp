#include "Day4.h"

#include "Utils.hpp"

#include <algorithm>

void Day4::Parse() {
    for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        card card;
        std::string line = *it;
        std::vector<std::string> vecStringCards = Utils::Split(line, ": ");
        card.id = std::stoi(Utils::Split(vecStringCards[0], ' ').back());
        std::vector<std::string> vecStringNumbers = Utils::Split(vecStringCards[1], " | ");
        std::vector<std::string> vecStringWinningNumbers = Utils::Split(vecStringNumbers[0], ' ');
        std::erase_if(vecStringWinningNumbers, [](const auto& s) {
            return s.length() == 0;
            });
        std::vector<std::string> vecStringPlayedNumbers = Utils::Split(vecStringNumbers[1], ' ');
        std::erase_if(vecStringPlayedNumbers, [](const auto& s) {
            return s.length() == 0;
            });

        for (const auto& strNumber : vecStringWinningNumbers) {
            card.winningNumbers.push_back(std::stoi(strNumber));
        }
        for (const auto& strNumber : vecStringPlayedNumbers) {
            card.playedNumbers.push_back(std::stoi(strNumber));
        }
        m_cards.push_back(card); 
    }
}

std::string Day4::Part1() {
    int totalPoints = 0;
    for (const card card : m_cards) {
        totalPoints += CalculateCardPoints(card);
    }
    return std::to_string(totalPoints);
}

std::string Day4::Part2() {
    return std::to_string(0);
}

int Day4::CalculateCardPoints(card card) {
    int cardPoints = 0;
    for (const int playedNumber : card.playedNumbers) {
        if (std::find(card.winningNumbers.begin(), card.winningNumbers.end(), playedNumber) == card.winningNumbers.end())
            continue;

        (cardPoints == 0) ? cardPoints = 1 : cardPoints = cardPoints * 2;
    }
    return cardPoints;
}