#include "Day8.h"

#include "Utils.hpp"

void Day8::Parse() {
    m_instructions = *data.begin();
    for (std::vector<std::string>::const_iterator it = data.begin() + 2; it != data.end(); it++) {
        auto tokens = Utils::Split(*it, " = ");
        auto instructionTokens = Utils::Split(tokens[1], ", ");
        m_nodes.insert(std::make_pair(tokens[0], node {
                tokens[0],
                instructionTokens[0].substr(1),
                instructionTokens[1].substr(0,3)
            }));
    }
}

std::string Day8::Part1() {
    int stepsTaken = 0;
    node currentNode = m_nodes.at("AAA");
    while (currentNode.name != "ZZZ") {
        int index = stepsTaken % m_instructions.length();
        char instruction = m_instructions[index];
        std::string nextNodeName = (instruction == 'L') ? m_nodes.at(currentNode.left).name : m_nodes.at(currentNode.right).name;
        currentNode = m_nodes.at(nextNodeName);
        stepsTaken++;
    }
    return(std::to_string(stepsTaken));
}

std::string Day8::Part2() {
    return std::to_string(0);
}