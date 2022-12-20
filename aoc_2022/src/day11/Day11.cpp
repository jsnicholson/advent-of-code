#include "Day11.h"

#include "Utils.hpp"

std::vector<std::pair<item,size_t>> g_thrownItems{};
int modulus = 1;

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
    for (int round = 0; round < 20; round++) {
        for (std::vector<Monkey*>::iterator it = m_monkeys.begin(); it != m_monkeys.end(); it++) {
            auto monkey = *it;
            monkey->InspectAllItems();
            CatchItems();
        }
    }

    std::vector<int> inspectionCounts{};
    for (std::vector<Monkey*>::const_iterator it = m_monkeys.begin(); it != m_monkeys.end(); it++) {
        auto monkey = *it;
        inspectionCounts.push_back(monkey->GetItemsInspectedCount());
    }
    std::sort(inspectionCounts.rbegin(), inspectionCounts.rend());

    uint64_t monkeyBusiness = inspectionCounts[0] * inspectionCounts[1];

    return std::to_string(monkeyBusiness);
}

std::string Day11::Part2() {
    modulus = 1;
    m_monkeys.clear();
    Parse();

    for (int round = 0; round < 10000; round++) {
        for (std::vector<Monkey*>::iterator it = m_monkeys.begin(); it != m_monkeys.end(); it++) {
            auto monkey = *it;
            monkey->InspectAllItems();
            CatchItems();
        }

        if (round == 9999) {
            std::cout << "===== Round " << round + 1 << " =====" << std::endl;
            for (int i = 0; i < m_monkeys.size(); i++) {
                std::cout << "Monkey " << i << ": " << m_monkeys[i]->GetItemsInspectedCount() << std::endl;
            }
        }
    }

    std::vector<uint64_t> inspectionCounts{};
    for (std::vector<Monkey*>::const_iterator it = m_monkeys.begin(); it != m_monkeys.end(); it++) {
        auto monkey = *it;
        inspectionCounts.push_back(monkey->GetItemsInspectedCount());
    }
    std::sort(inspectionCounts.rbegin(), inspectionCounts.rend());

    uint64_t monkeyBusiness = inspectionCounts[0] * inspectionCounts[1];

    return std::to_string(monkeyBusiness);
}

bool Day11::DoesStringStartWithToken(const std::string string, const std::string token) {
    return string.rfind(token, 0) == 0;
}

void Day11::CatchItems() {
    size_t itemsToCatch = g_thrownItems.size();
    for (size_t count = 0; count < itemsToCatch; count++) {
        auto entry = g_thrownItems.front();
        auto item = entry.first;
        auto monkeyToCatch = entry.second;
        m_monkeys[monkeyToCatch]->CatchItem(item);
    }
}

Monkey::Monkey(std::string plainTextDescription) : m_itemsInspected(0), m_testDivisibleBy(0), m_ifTestTrueThrowToMonkeyNumber(0), m_ifTestFalseThrowToMonkeyNumber(0) {
    std::vector<std::string> lines = Utils::Split(plainTextDescription, '\n');
    size_t found;
    for (std::vector<std::string>::const_iterator it = lines.begin(); it != lines.end(); it++) {
        std::string line = *it;
        for (const auto& entry : Monkey::m_mapTokensToProcess) {
            if (found = line.find(entry.first) != std::string::npos)
                entry.second(line.substr(found + entry.first.length() + 1));
        }
    }
}

void Monkey::ProcessStartingItems(const std::string startingItemsString) {
    const auto values = Utils::Split(startingItemsString, ", ");
    for (size_t count = 0; count < values.size(); count++)
        m_items.push_back(std::stoi(values[count]));
}

void Monkey::ProcessOperation(const std::string operationString) {
    const auto tokens = Utils::Split(operationString, ' ');
    const char op = tokens[3][0];
    const TermType termType = (tokens[4] != "old") ? TermType::constant : TermType::variable;
    const int term = (termType == TermType::constant) ? std::stoi(tokens[4]) : INT_MIN;
    m_operation = [op, term, termType](item& valueToUpdate) {
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

    modulus *= m_testDivisibleBy;
}

void Monkey::ProcessTestTrue(const std::string testTrueString) {
    const auto tokens = Utils::Split(testTrueString, ' ');
    m_ifTestTrueThrowToMonkeyNumber = std::stoi(tokens[4]);
}

void Monkey::ProcessTestFalse(const std::string testFalseString) {
    const auto tokens = Utils::Split(testFalseString, ' ');
    m_ifTestFalseThrowToMonkeyNumber = std::stoi(tokens[4]);
}

void Monkey::InspectAllItems() {
    int itemCount = m_items.size();
    for (int count = 0; count < itemCount; count++) {
        InspectFirstItem();
        m_itemsInspected++;
        size_t whereToThrowItem = DecideWhereToThrowItem();
        ThrowItem(whereToThrowItem);
    }
}

void Monkey::InspectFirstItem() {
    auto& item = m_items.front();
    m_operation(item);
    item = item % modulus;
}

size_t Monkey::DecideWhereToThrowItem() {
    auto item = m_items.front();
    return (item % m_testDivisibleBy == 0) ? m_ifTestTrueThrowToMonkeyNumber : m_ifTestFalseThrowToMonkeyNumber;
}

void Monkey::ThrowItem(const size_t monkeyToThrowTo) {
    auto frontItem = m_items.front();
    m_items.erase(m_items.begin());
    g_thrownItems.push_back( { frontItem, monkeyToThrowTo } );
}

void Monkey::CatchItem(const item itemCaught) {
    m_items.push_back(itemCaught);
    g_thrownItems.erase(g_thrownItems.begin());
}

void Monkey::ShowItems() {
    for (std::vector<item>::const_iterator it = m_items.begin(); it != m_items.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}