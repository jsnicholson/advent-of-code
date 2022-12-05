#include "Day2.h"

#include <map>
#include <algorithm>

const std::map<char, char> mapCodeToRockPaperScissors{
    {'A','R'},
    {'B','P'},
    {'C','S'},
    {'X','R'},
    {'Y','P'},
    {'Z','S'}
};

const std::map<char, int> mapRockPaperScissorsToScore{
    {'R',1},
    {'P',2},
    {'S',3}
};

const std::map<char, char> mapRockPaperScissorsToLosesTo{
    {'R','P'},
    {'P','S'},
    {'S','R'}
};

const std::map<char, char> mapRockPaperScissorsToWinsAgainst{
    {'R','S'},
    {'P','R'},
    {'S','P'}
};

void Day2::Parse() {
    for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        auto theyPlay = mapCodeToRockPaperScissors.at((*it)[0]);
        auto youPlay = mapCodeToRockPaperScissors.at((*it)[2]);
        auto round = std::make_pair((*it)[0], (*it)[2]);
        m_rounds.push_back(round);
    }
}

int Day2::Part1() {
    int totalScore = 0;
    for (std::list<round>::iterator it = m_rounds.begin(); it != m_rounds.end(); it++) {
        round round = *it;
        round.first = mapCodeToRockPaperScissors.at((*it).first);
        round.second = mapCodeToRockPaperScissors.at((*it).second);
        totalScore += CalculateRoundScore(round);
    }
    return totalScore;
}

int Day2::Part2() {
    int totalScore = 0;
    for (std::list<round>::iterator it = m_rounds.begin(); it != m_rounds.end(); it++) {
        round round = *it;
        round.first = mapCodeToRockPaperScissors.at(round.first);
        round.second = CalculateWhatToPlay(round);
        totalScore += CalculateRoundScore(round);
    }
    return totalScore;
}

int Day2::CalculateRoundScore(round round) {
    int base = mapRockPaperScissorsToScore.at(round.second);

    // tie = 3 points
    if (round.first == round.second)
        base += 3;
    // rock beats scissors
    else if (round.second == 'R' && round.first == 'S')
        base += 6;
    // scissors loses to rock
    else if (round.second == 'S' && round.first == 'R') { /*lost*/ }
    // other cases solved with comparison
    else if (mapRockPaperScissorsToScore.at(round.second) > mapRockPaperScissorsToScore.at(round.first))
        base += 6;

    return base;
}

char Day2::CalculateWhatToPlay(round round) {
    switch (round.second) {
        // calculate lose
        case 'X':
            return mapRockPaperScissorsToWinsAgainst.at(round.first);
        // draw
        case 'Y':
            return round.first;
            break;
        // calculate win
        case 'Z':
            return mapRockPaperScissorsToLosesTo.at(round.first);
            break;
        default:
            return ' ';
            break;
    }
}