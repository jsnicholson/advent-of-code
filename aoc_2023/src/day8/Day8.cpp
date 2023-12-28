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
        char instruction = m_instructions[stepsTaken % m_instructions.length()];
        AdvanceNode(currentNode, instruction);
        stepsTaken++;
    }
    return(std::to_string(stepsTaken));
}

std::string Day8::Part2() {
    int stepsTaken = 0;
    std::vector<std::pair<node,ull>> nodes;
    for (const auto& [key, value] : m_nodes) {
        if (value.name[2] == 'A')
            nodes.push_back(std::make_pair(value,ULLONG_MAX));
    }

    for (auto& nodeWithLoopLength : nodes) {
        node& currentNode = nodeWithLoopLength.first;
        ull stepsTaken = 0;
        while (currentNode.name[2] != 'Z') {
            char instruction = m_instructions[stepsTaken % m_instructions.length()];
            AdvanceNode(currentNode, instruction);
            stepsTaken++;
        }
        nodeWithLoopLength.second = stepsTaken;
    }

    ull total = nodes[0].second;
    for (const auto& node : nodes)
        total = LowestCommonMultiple(total, node.second);

    return std::to_string(total);
}

void Day8::AdvanceNode(node& node, char instruction) {
    std::string nextNodeName = (instruction == 'L') ? m_nodes.at(node.left).name : m_nodes.at(node.right).name;
    node = m_nodes.at(nextNodeName);
}

Day8::ull Day8::GreatestCommonDenominator(ull a, ull b) {
    while (b != 0) {
        ull temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

Day8::ull Day8::LowestCommonMultiple(ull a, ull b) {
    return (a * b / GreatestCommonDenominator(a, b));
}