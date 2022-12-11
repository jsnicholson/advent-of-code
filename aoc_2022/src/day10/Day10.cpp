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
        auto states = ExecuteInstruction(cycle, xRegister, instruction);
        StatesToInterestingSignalStrengths(states, interestingSignalStrengths);
    }

    size_t sum = std::accumulate(interestingSignalStrengths.begin(), interestingSignalStrengths.end(), 0,
                    [](const int prev, const std::pair<int, int>& entry) {
                            return prev + entry.second;
                            });
    return std::to_string(sum);
}

// part2 doesnt produce a direct value, but produces a output that resembles drawn characters
std::string Day10::Part2() {
    int xRegister = 1, cycle = 0;
    std::string output{"\n "};
    
    for (std::vector<std::string>::const_iterator it = m_instructions.begin(); it != m_instructions.end(); it++) {
        std::string instruction = *it;
        auto states = ExecuteInstruction(cycle, xRegister, instruction);
        StatesToScreenOutput(states, output);
    }
    return output;
}

std::vector<Day10::state> Day10::ExecuteInstruction(int& cycle, int& xRegister, const std::string instruction) {
    std::vector<state> states{};
    cycle++;
    states.push_back(std::make_pair(cycle, xRegister));

    auto tokens = Utils::Split(instruction, ' ');
    if (tokens[0] == "addx") {
        xRegister += std::stoi(tokens[1]);
        cycle++;
        states.push_back(std::make_pair(cycle, xRegister));
    }

    return states;
}

void Day10::StatesToInterestingSignalStrengths(const std::vector<state> states, std::map<int, int>& interestingSignalStrengths) {
    std::map<int, int>::iterator it;
    for (const auto state : states) {
        const int cycle = state.first;
        const int xRegister = state.second;
        it = interestingSignalStrengths.find(cycle);
        if (it != interestingSignalStrengths.end())
            it->second = cycle * xRegister;
    }
}

void Day10::StatesToScreenOutput(const std::vector<state> states, std::string& output) {
    for (const auto state : states) {
        const int cycle = state.first;
        const int xRegister = state.second;
        if (cycle % m_screenWidth == 0)
            output.append("\n");
        IsPixelLit(xRegister, cycle) ? output.append("#") : output.append(" ");
    }
}

bool Day10::IsPixelLit(const int xRegister, const int cathodeRayIndex) {
    const int horizontalLocation = cathodeRayIndex % m_screenWidth;
    return (xRegister - 1 <= horizontalLocation && horizontalLocation <= xRegister + 1);
}