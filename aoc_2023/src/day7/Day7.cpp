#include "Day7.h"

#include <format>

#include "Utils.hpp"

void Day7::Parse() {
    for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        std::string line = *it;
        auto tokens = Utils::Split(line, ' ');
        m_plays.push_back(play{
                tokens[0],
                std::stoi(tokens[1])
            });
    }
}

std::string Day7::Part1() {
    std::vector<std::pair<play, type>> rankedPlays;
    for (const auto& play : m_plays)
        rankedPlays.push_back(std::make_pair(play,GetHandType(play.hand)));

    std::sort(rankedPlays.rbegin(), rankedPlays.rend(), Day7::CompareRank);

    return std::to_string(CalculateWinnings(rankedPlays));
}

std::string Day7::Part2() {
    return std::to_string(0);
}

Day7::type Day7::GetHandType(std::string hand) {
    auto distribution = GetCharacterDistribution(hand);

    if (distribution.size() == 1 && distribution[0].second == 5)
        return type::five_of_a_kind;

    if (distribution.size() == 2 && distribution[0].second == 4)
        return type::four_of_a_kind;

    if (distribution.size() == 2 && distribution[0].second == 3)
        return type::full_house;

    if (distribution.size() == 3 && distribution[0].second == 3)
        return type::three_of_a_kind;

    if (distribution.size() == 3 && distribution[0].second == 2 && distribution[1].second == 2)
        return type::two_pair;

    if (distribution.size() == 4 && distribution[0].second == 2)
        return type::one_pair;

    return type::high_card;
}

std::vector<std::pair<char,int>> Day7::GetCharacterDistribution(std::string str) {
    std::vector<std::pair<char, int>> distribution = {};
    for (const auto& character : str) {
        auto it = std::find_if(distribution.begin(), distribution.end(),
            [character](const std::pair<char,int>& element) {
                return element.first == character;
            });
        if (it != distribution.end())
            it->second++;
        else
            distribution.push_back(std::make_pair(character,1));
    }
    std::sort(distribution.begin(), distribution.end(),
        [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
    return distribution;
}

bool Day7::CompareRank(const std::pair<play, type>& a, const std::pair<play, type>& b) {
    if (a.second != b.second)
        return a.second > b.second;

    for (int i = 0; i < 5; i++) {
        if (a.first.hand[i] == b.first.hand[i])
            continue;

        return GetCardValue(a.first.hand[i]) > GetCardValue(b.first.hand[i]);
    }
}

int Day7::GetCardValue(const char c) {
    if (std::isdigit(c))
        return c - '0';

    return m_mapNonNumericCardValueToNumber.at(c);
}

int Day7::CalculateWinnings(const std::vector<std::pair<play, type>> rankedPlays) {
    int winnings = 0;
    for (int i = 0; i < rankedPlays.size(); i++)
        winnings += (i + 1) * rankedPlays[i].first.bid;
    return winnings;
}
