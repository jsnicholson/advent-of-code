#include "Day2.h"

#include <map>
#include <algorithm>

const std::map<char, char> mapCodeToRockPaperScissors {
    {'A','R'},
    {'B','P'},
    {'C','S'},
    {'X','R'},
    {'Y','P'},
    {'Z','S'}
};

const std::map<char, int> mapRockPaperScissorsToScore {
    {'R',1},
    {'P',2},
    {'S',3}
};

void Day2::Parse() {
    for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        auto theyPlay = mapCodeToRockPaperScissors.at((*it)[0]);
        auto youPlay = mapCodeToRockPaperScissors.at((*it)[2]);
        auto round = std::make_pair(theyPlay, youPlay);
        m_rounds.push_back(round);
    }
}

int Day2::Part1() {
    int totalScore = 0;
    for (std::list<round>::iterator it = m_rounds.begin(); it != m_rounds.end(); it++)
        totalScore += CalculateRoundScore(*it);
    return totalScore;
}

int Day2::Part2() {
    return -1;
}

int Day2::CalculateRoundScore(round round) {
    int base = mapRockPaperScissorsToScore.at(round.second);

    if (round.first == round.second)
        base += 3;
    else if (round.second == 'R' && round.first == 'S')
        base += 6;
    else if (round.second == 'S' && round.first == 'R') { /*lost*/ }
    else if (mapRockPaperScissorsToScore.at(round.second) > mapRockPaperScissorsToScore.at(round.first))
        base += 6;

    return base;
}