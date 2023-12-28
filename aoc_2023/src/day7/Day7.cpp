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
    for (const auto play : m_plays)
        rankedPlays.push_back(std::make_pair(play,GetHandType(play.hand)));

    std::sort(rankedPlays.rbegin(), rankedPlays.rend(), Day7::CompareRank);

    return std::to_string(CalculateWinnings(rankedPlays));
}

std::string Day7::Part2() {
    std::vector<std::pair<play, type>> rankedPlays;
    for (const auto play : m_plays) {
        auto mutableHand = play.hand;
        ProcessJoker(mutableHand);
        rankedPlays.push_back(std::make_pair(play, GetHandType(mutableHand)));
    }

    std::sort(rankedPlays.rbegin(), rankedPlays.rend(), Day7::CompareRank);

    return std::to_string(CalculateWinnings(rankedPlays));
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
            if (a.second == b.second)
                GetCardValue(a.first) > GetCardValue(b.first);

            return a.second > b.second;
        });
    return distribution;
}

bool Day7::CompareRank(const std::pair<play, type>& a, const std::pair<play, type>& b) {
    if (a.second != b.second)
        return a.second > b.second;

    for (int i = 0; i < 5; i++) {
        char charA = a.first.hand[i];
        char charB = b.first.hand[i];

        if (charA == charB)
            continue;

        return GetCardValue(charA) > GetCardValue(charB);
    }
}

int Day7::GetCardValue(const char c) {
    if (std::isdigit(c))
        return c - '0';

    return m_mapNonNumericCardValueToNumber.at(c);
}

Day7::ull Day7::CalculateWinnings(const std::vector<std::pair<play, type>> rankedPlays) {
    ull winnings = 0;
    for (int i = 0; i < rankedPlays.size(); i++)
        winnings += (static_cast<ull>(i) + 1) * static_cast<ull>(rankedPlays[i].first.bid);
    return winnings;
}

void Day7::ProcessJoker(std::string& hand){
    auto distribution = GetCharacterDistribution(hand);
    // no jokers, just ignore
    if (std::find_if(distribution.begin(), distribution.end(),
        [](const auto& element) {
            return element.first == 'J';
        }) == distribution.end()) {
        return;
    }

    // rare edge case all Joker
    if (distribution.size() == 1 && distribution[0].first == 'J' && distribution[0].second == 5) {
        Utils::StringReplace(hand, 'J', 'A');
        return;
    }

    char jokerReplacementCard = (distribution[0].first == 'J') ? distribution[1].first : distribution[0].first;
    Utils::StringReplace(hand, 'J', jokerReplacementCard);
}