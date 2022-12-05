#include "Day5.h"

#include <cmath>
#include <regex>
#include <iostream>

void Day5::Parse() {
    int indexCrateDefinitionLine = 0;
    std::vector<int> crateStackPositions{};

    // find the line that defines stacks, and check their position
    for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        std::string line = *it;
        if (line.find('[') == std::string::npos) {
            indexCrateDefinitionLine = abs(std::distance(it, data.begin()));
            for (int i = 0; i < line.length(); i++) {
                char c = line[i];
                if (c != ' ') {
                    crateStackPositions.push_back(i);
                    m_cratestacks.push_back(cratestack{});
                }
            }
            break;
        }
    }
    // add all crates to their respective stacks
    {
        std::vector<std::string>::reverse_iterator it = std::prev(data.rend(), indexCrateDefinitionLine);
        for (it; it != data.rend(); it++) {
            std::string line = *it;
            int indexCrateStack = 0;
            for (std::vector<int>::iterator iteratorCrateStackPosition = crateStackPositions.begin(); iteratorCrateStackPosition != crateStackPositions.end(); iteratorCrateStackPosition++) {
                char crateChar = line[*iteratorCrateStackPosition];
                if (crateChar != ' ')
                    m_cratestacks[indexCrateStack].push(crateChar);
                indexCrateStack++;
            }
        }
    }
    // parse instructions
    {
        std::vector<std::string>::iterator it = std::next(data.begin(), indexCrateDefinitionLine+2);
        for (it; it != data.end(); it++) {
            std::string line = *it;
            auto tokens = Split(line, std::string(" "));
            int count = std::stoi(tokens[1]);
            int from = std::stoi(tokens[3]);
            int to = std::stoi(tokens[5]);
            instruction instruction = std::make_pair(count, std::make_pair(from, to));
            m_instructions.push_back(instruction);
        }
    }
}

std::string Day5::Part1() {
    std::vector<cratestack> cratestacks = m_cratestacks;
    for (std::vector<instruction>::iterator it = m_instructions.begin(); it != m_instructions.end(); it++) {
        instruction instruction = *it;
        int count = instruction.first, from = instruction.second.first-1, to = instruction.second.second-1;
        for (int i = 0; i < count; i++) {
            if (!cratestacks[from].empty()) {
                auto crate = cratestacks[from].top();
                cratestacks[from].pop();
                cratestacks[to].push(crate);
            }
        }
    }

    std::string result;
    for (int i = 0; i < cratestacks.size(); i++) {
        result+=(cratestacks[i].top());
    }

    return result;
}

std::string Day5::Part2() {
    std::vector<cratestack> cratestacks = m_cratestacks;
    for (std::vector<instruction>::iterator it = m_instructions.begin(); it != m_instructions.end(); it++) {
        instruction instruction = *it;
        int count = instruction.first, from = instruction.second.first - 1, to = instruction.second.second - 1;
        cratestack tempCrateStack{};
        for (int i = 0; i < count; i++) {
            if (!cratestacks[from].empty()) {
                auto crate = cratestacks[from].top();
                cratestacks[from].pop();
                tempCrateStack.push(crate);
            }
        }
        const int size = tempCrateStack.size();
        for (int i = 0; i < size; i++) {
            auto crate = tempCrateStack.top();
            tempCrateStack.pop();
            cratestacks[to].push(crate);
        }
    }

    std::string result;
    for (int i = 0; i < cratestacks.size(); i++) {
        if (!cratestacks[i].empty())
            result += (cratestacks[i].top());
    }

    return result;
}

std::vector<std::string> Day5::Split(std::string string, std::string delimiter) {
    std::vector<std::string> splits{};
    size_t pos = 0;
    std::string token;
    while ((pos = string.find(delimiter)) != std::string::npos) {
        token = string.substr(0, pos);
        splits.push_back(token);
        string.erase(0, pos + delimiter.length());
    }
    splits.push_back(string);
    return splits;
}

std::vector<std::string> Day5::Split(std::string string, char delimiter) {
    std::vector<std::string> splits{};
    size_t pos = 0;
    std::string token;
    while ((pos = string.find(delimiter)) != std::string::npos) {
        token = string.substr(0, pos);
        splits.push_back(token);
        string.erase(0, pos + 1);
    }
    splits.push_back(string);
    return splits;
}