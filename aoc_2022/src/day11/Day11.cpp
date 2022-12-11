#include "Day11.h"

#include "Utils.hpp"

void Day11::Parse() {
    std::string monkeyPlainTextDescription{};
    for (std::vector<std::string>::const_iterator it = data.begin(); it != data.end(); it++) {
        std::string line = *it;
        if (line.empty()) {
            m_monkeys.push_back(new Monkey(monkeyPlainTextDescription));
            monkeyPlainTextDescription.clear();
            continue;
        }

        if (DoesStringStartWithToken(line, "Monkey")) {
            continue;
        }

        monkeyPlainTextDescription.append(((!monkeyPlainTextDescription.empty()) ? std::string("\n") : std::string("")) + line);
    }
    if (!monkeyPlainTextDescription.empty())
        m_monkeys.push_back(new Monkey(monkeyPlainTextDescription));
}

std::string Day11::Part1() {
    return std::string("unimplemented");
}

std::string Day11::Part2() {
    return std::string("unimplemented");
}

bool Day11::DoesStringStartWithToken(const std::string string, const std::string token) {
    return string.rfind(token, 0) == 0;
}

Monkey::Monkey(std::string plainTextDescription) : m_testDivisibleBy(0), m_ifTestTrueThrowToMonkeyNumber(0), m_ifTestFalseThrowToMonkeyNumber(0) {
    std::vector<std::string> lines = Utils::Split(plainTextDescription, '\n');
    size_t found;
    for (std::vector<std::string>::const_iterator it = lines.begin(); it != lines.end(); it++) {
        std::string line = *it;
        for (const auto& entry : Monkey::m_mapTokensToProcess) {
            if (found = line.find(entry.first) != std::string::npos)
                entry.second(line.substr(found + entry.first.length() + 1));
        }

        //if (found = line.find(m_tokenStartingItems) != std::string::npos)
        //    ProcessStartingItems(line.substr(found + m_tokenStartingItems.length() + 1));
        //else if (found = line.find(m_tokenOperation) != std::string::npos)
        //    ProcessOperation(line.substr(found + m_tokenOperation.length() + 1));
        //else if (found = line.find(m_tokenTestDivisbleBy) != std::string::npos)
        //    ProcessTest(line.substr(found + m_tokenTestDivisbleBy.length() + 1));
        //else if (found = line.find(m_tokenTrue) != std::string::npos)
        //    ProcessTestTrue(line.substr(found + m_tokenTrue.length() + 1));
        //else if (found = line.find(m_tokenFalse) != std::string::npos)
        //    ProcessTestFalse(line.substr(found + m_tokenFalse.length() + 1));
    }
}

void Monkey::ProcessStartingItems(const std::string startingItemsString) {
    const auto values = Utils::Split(startingItemsString, ", ");
    for (int count = 0; count < values.size(); count++)
        m_items.push_back(std::stoi(values[count]));
}

void Monkey::ProcessOperation(const std::string operationString) {
    const auto tokens = Utils::Split(operationString, ' ');
    const char op = tokens[3][0];
    const TermType termType = (tokens[4] != "old") ? TermType::constant : TermType::variable;
    const int term = (termType == TermType::constant) ? std::stoi(tokens[4]) : INT_MIN;
    m_operation = [op, term, termType](int& valueToUpdate) {
        if (termType == TermType::constant) {
            if (op == '+')
                valueToUpdate += term;
            else if (op == '*')
                valueToUpdate *= term;
        } else if (termType == TermType::variable) {
            if (op == '+')
                valueToUpdate += valueToUpdate;
            else if (op == '*')
                valueToUpdate *= valueToUpdate;
        }
    };
}

void Monkey::ProcessTest(const std::string testString) {
    const auto tokens = Utils::Split(testString, ' ');
    m_testDivisibleBy = std::stoi(tokens[2]);
}

void Monkey::ProcessTestTrue(const std::string testTrueString) {
    const auto tokens = Utils::Split(testTrueString, ' ');
    m_ifTestTrueThrowToMonkeyNumber = std::stoi(tokens[4]);
}

void Monkey::ProcessTestFalse(const std::string testFalseString) {
    const auto tokens = Utils::Split(testFalseString, ' ');
    m_ifTestFalseThrowToMonkeyNumber = std::stoi(tokens[4]);
}