#include "Day4.h"

#include "Utils.hpp"

#include <algorithm>
#include <list>

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
        int matches = CalculateCardMatches(card);
        totalPoints += (matches > 0) ? 1 << (matches - 1) : 0;
    }
    return std::to_string(totalPoints);
}

std::string Day4::Part2() {
    std::vector<int> cardCounts(m_cards.size());
    std::fill(cardCounts.begin(), cardCounts.end(), 1);
    for (int i = 0; i < cardCounts.size(); i++) {
        card card = m_cards.at(i);
        int matches = CalculateCardMatches(card);
        for (int m = 1; m <= matches; m++) {
            cardCounts[i + m] += cardCounts[i];
        }
    }

    return std::to_string(std::accumulate(cardCounts.begin(), cardCounts.end(), 0));
}

int Day4::CalculateCardMatches(card card) {
    int matches = 0;
    for (const int playedNumber : card.playedNumbers) {
        if (std::find(card.winningNumbers.begin(), card.winningNumbers.end(), playedNumber) == card.winningNumbers.end())
            continue;

        matches++;
    }
    return matches;
}