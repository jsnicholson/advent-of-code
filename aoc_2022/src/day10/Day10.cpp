#include "Day10.h"

#include "Utils.hpp"

void Day10::Parse() {
    m_instructions = data;
}

std::string Day10::Part1() {
    int xRegister = 1, cycle = 1;
    std::map<int, int> interestingSignalStrengths{ {20,0},{60,0},{100,0},{140,0},{180,0},{220,0} };
    
    for (std::vector<std::string>::const_iterator it = m_instructions.begin(); it != m_instructions.end(); it++) {
        std::string instruction = *it;
        auto tokens = Utils::Split(instruction, ' ');
        std::map<int, int> signalStrengths{};
        if (tokens[0] == "noop") {
            signalStrengths = ProcessNoopCommand(cycle, xRegister);
        } else if (tokens[0] == "addx") {
            signalStrengths= ProcessAddXCommand(std::stoi(tokens[1]), cycle, xRegister);
        }

        UpdateInterestingValues(signalStrengths, interestingSignalStrengths);
    }

    size_t sum = std::accumulate(interestingSignalStrengths.begin(), interestingSignalStrengths.end(), 0,
                    [](const int prev, const std::pair<int, int>& entry) {
                            return prev + entry.second;
                            });
    return std::to_string(sum);
}

std::string Day10::Part2() {
    std::string output{"\n "};
    int xRegister = 1, cycle = 1;
    
    for (std::vector<std::string>::const_iterator it = m_instructions.begin(); it != m_instructions.end(); it++) {
        std::string instruction = *it;
        auto tokens = Utils::Split(instruction, ' ');
        if (cycle % m_screenWidth == 0)
            output.append("\n");     
        (IsPixelLit(xRegister, cycle)) ? output.append("#") : output.append(" ");
        cycle++;
        
        if (tokens[0] == "addx") {
            xRegister += std::stoi(tokens[1]);
            if (cycle % m_screenWidth == 0)
                output.append("\n");
            (IsPixelLit(xRegister, cycle)) ? output.append("#") : output.append(" ");
            cycle++;
        }
    }
    return output;
}

std::map<int,int> Day10::ProcessNoopCommand(int& cycle, const int xRegister) {
    cycle++;
    return std::map<int, int>{ {cycle,cycle*xRegister} };
}

std::map<int,int> Day10::ProcessAddXCommand(const int addValue, int& cycle, int& xRegister) {
    std::map<int, int> signalStrengths{};
    cycle++;
    signalStrengths.insert({cycle, cycle*xRegister});

    cycle++;
    xRegister += addValue;
    signalStrengths.insert({ cycle, cycle * xRegister });
    
    return signalStrengths;
}

void Day10::UpdateInterestingValues(const std::map<int, int> signalStrengths, std::map<int, int>& interestingSignalStrengths) {
    std::map<int, int>::iterator it;
    for (const auto& signalStrength : signalStrengths) {
        const int cycle = signalStrength.first;
        it = interestingSignalStrengths.find(cycle);
        if (it != interestingSignalStrengths.end()) {
            it->second = signalStrength.second;
        }
    }
}

bool Day10::IsPixelLit(const int xRegister, const int cathodeRayIndex) {
    const int horizontalLocation = cathodeRayIndex % m_screenWidth;
    return (xRegister - 1 <= horizontalLocation && horizontalLocation <= xRegister + 1);
}

void Day10::ProduceScreenOutput(const int cycle, const int xRegister, std::string& output) {
    if (cycle % m_screenWidth == 0)
        output.append("\n");
    IsPixelLit(xRegister, cycle) ? output.append("#") : output.append(" ");
}