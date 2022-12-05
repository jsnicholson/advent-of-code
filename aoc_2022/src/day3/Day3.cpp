#include "Day3.h"
#include "Utils.hpp"

#include <algorithm>

void Day3::Parse() {
    for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        m_rucksacks.push_back(*it);
    }
}

int Day3::Part1() {
    int sum = 0;
    for (std::list<std::string>::iterator it = m_rucksacks.begin(); it != m_rucksacks.end(); it++) {
        auto rucksack = *it;
        auto repeatedItem = FindRepeatedItemInRucksack(rucksack);
        int priority = CalculateItemPriority(repeatedItem);
        sum += priority;
    }
    return sum;
}

int Day3::Part2() {
    int sum = 0;
    for (std::list<rucksack>::iterator it = m_rucksacks.begin(); it != m_rucksacks.end(); std::advance(it, 3)) {
        rucksack firstRucksack = *it;
        rucksack secondRucksack = *(std::next(it, 1));
        rucksack thirdRucksack = *(std::next(it, 2));

        std::sort(firstRucksack.begin(), firstRucksack.end());
        std::sort(secondRucksack.begin(), secondRucksack.end());
        std::sort(thirdRucksack.begin(), thirdRucksack.end());
        
        auto intersection = FindIntersectionOfThreeRucksacks(firstRucksack, secondRucksack, thirdRucksack);

        if (intersection.size() > 1) {
            std::cerr << "more than one badge, something went wrong" << std::endl;
            EXIT_FAILURE;
            return -1;
        }

        char badge = intersection.front();
        int priority = CalculateItemPriority(badge);
        sum += priority;
    }

    return sum;
}

Day3::splitRucksack Day3::SplitRucksackIntoTwoEvenCompartments(rucksack wholeRucksack) {
    std::string firstHalf = wholeRucksack.substr(0, wholeRucksack.length() / 2);
    std::string secondHalf = wholeRucksack.substr(wholeRucksack.length() / 2);
    return std::make_pair(firstHalf, secondHalf);
}

char Day3::FindRepeatedItemInRucksack(rucksack rucksack) {
    auto splitRucksack = SplitRucksackIntoTwoEvenCompartments(rucksack);
    for (std::string::iterator it = splitRucksack.first.begin(); it != splitRucksack.first.end(); it++) {
        char item = *it;
        if (splitRucksack.second.find(item) != std::string::npos)
            return item;
        else
            continue;
    }
    std::cerr << "no repeated item" << std::endl;
    EXIT_FAILURE;
    return NULL;
}

int Day3::CalculateItemPriority(char item) {
    if (item >= 'A' && item <= 'Z')
        return item - 38;
    else if (item >= 'a' && item <= 'z')
        return item - 96;
    else {
        EXIT_FAILURE;
        return NULL;
    }
}

std::list<char> Day3::FindIntersectionOfThreeRucksacks(rucksack first, rucksack second, rucksack third) {
    std::list<char> commonCharsBetweenTwoRucksacks;
    std::set_intersection(first.begin(), first.end(),
        second.begin(), second.end(),
        std::back_inserter(commonCharsBetweenTwoRucksacks));

    std::list<char> commonCharsBetweenThreeRucksacks;
    std::set_intersection(commonCharsBetweenTwoRucksacks.begin(), commonCharsBetweenTwoRucksacks.end(),
        third.begin(), third.end(),
        std::back_inserter(commonCharsBetweenThreeRucksacks));

    commonCharsBetweenThreeRucksacks.unique();
    return commonCharsBetweenThreeRucksacks;
}