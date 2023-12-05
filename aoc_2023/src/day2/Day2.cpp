#include "Day2.h"

#include "Utils.hpp"

void Day2::Parse() {
    for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        std::string line = *it;
        std::vector<std::string> tokens = Utils::Split(line, ": ");
        std::vector<std::string> idTokens = Utils::Split(tokens[0], ' ');
        std::string strGame = tokens[1];
        std::vector<std::string> strRounds = Utils::Split(strGame, "; ");

        game g = game();
        g.id = std::stoi(idTokens[1]);
        for (const auto& strRound : strRounds) {
            std::vector<std::string> strReveals = Utils::Split(strRound, ", ");

            round r = round();
            for (const auto& strReveal : strReveals) {
                std::vector<std::string> revealTokens = Utils::Split(strReveal, ' ');
                if (revealTokens[1] == "red")
                    r.red = std::stoi(revealTokens[0]);
                else if (revealTokens[1] == "green")
                    r.green = std::stoi(revealTokens[0]);
                else if (revealTokens[1] == "blue")
                    r.blue = std::stoi(revealTokens[0]);
            }
            g.rounds.push_back(r);
        }
        m_games.push_back(g);
    }
}

std::string Day2::Part1() {
    std::vector<int> vectorImpossibleGameIds = {};
    for (const auto& game : m_games) {
        for (const auto& round : game.rounds) {
            if (round.red > maxRed
                || round.green > maxGreen
                || round.blue > maxBlue) {
                vectorImpossibleGameIds.push_back(game.id);
                break;
            }
        }
    }
    return std::to_string(5050 - std::accumulate(vectorImpossibleGameIds.begin(), vectorImpossibleGameIds.end(), 0));
}

std::string Day2::Part2() {
    std::vector<int> vectorCubePower = {};
    for (const auto& game : m_games) {
        int maxRedSeen = 0, maxGreenSeen = 0, maxBlueSeen = 0;
        for (const auto& round : game.rounds) {
            maxRedSeen = std::max(maxRedSeen, round.red);
            maxGreenSeen = std::max(maxGreenSeen, round.green);
            maxBlueSeen = std::max(maxBlueSeen, round.blue);
        }
        vectorCubePower.push_back(maxRedSeen * maxGreenSeen * maxBlueSeen);
    }
    return std::to_string(std::accumulate(vectorCubePower.begin(),vectorCubePower.end(),0));
}