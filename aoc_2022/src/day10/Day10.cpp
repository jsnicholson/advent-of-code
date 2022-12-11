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
        cycle++;
        UpdateInterestingValues(cycle, xRegister, interestingSignalStrengths);      
        if (tokens[0] == "addx") {
            xRegister += std::stoi(tokens[1]);
            cycle++;
            UpdateInterestingValues(cycle, xRegister, interestingSignalStrengths);     
        }
    }

    size_t sum = std::accumulate(interestingSignalStrengths.begin(), interestingSignalStrengths.end(), 0,
                    [](const int prev, const std::pair<int, int>& entry) {
                            return prev + entry.second;
                            });
    return std::to_string(sum);
}

// part2 doesnt produce a direct value, but produces a output that resembles drawn characters
std::string Day10::Part2() {
    std::string output{"\n "};
    int xRegister = 1, cycle = 0;
    
    for (std::vector<std::string>::const_iterator it = m_instructions.begin(); it != m_instructions.end(); it++) {
        std::string instruction = *it;
        auto tokens = Utils::Split(instruction, ' ');
        
        cycle++;
        ProduceScreenOutput(cycle, xRegister, output);
        
        if (tokens[0] == "addx") {
            xRegister += std::stoi(tokens[1]);
            
            cycle++;
            ProduceScreenOutput(cycle, xRegister, output);
        }
    }
    return output;
}

void Day10::UpdateInterestingValues(const int cycle, const int xRegister, std::map<int, int>& interestingSignalStrengths) {
    std::map<int, int>::iterator it = interestingSignalStrengths.find(cycle);
    if (it != interestingSignalStrengths.end())
        it->second = cycle * xRegister;
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