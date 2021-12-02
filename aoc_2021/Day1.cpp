#include "day1.h"
#include <assert.h>
#include <fstream>
#include <iostream>

void Day1::Parse() {
    for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        depths.push_back(std::stoi(*it));
    }
}

int Day1::Part1() {
    return HowManyIncreased(depths);
}

int Day1::Part2() {
    size_t howManyIncreased = 0;
    std::list<int> threeNumberWindow;
    for (std::list<int>::iterator it1 = depths.begin(), it2 = ++depths.begin(), it3 = ++++depths.begin();
        it3 != depths.end(); ++it1, ++it2, ++it3) {

        threeNumberWindow.push_back(*it1 + *it2 + *it3);
    }

    return HowManyIncreased(threeNumberWindow);
}

int Day1::HowManyIncreased(std::list<int> numbers) {
    size_t howManyIncreased = 0;

    for (std::list<int>::iterator it1 = numbers.begin(), it2 = ++numbers.begin();
        it2 != numbers.end(); ++it1, ++it2) {

        if (*it2 > *it1)
            howManyIncreased++;
    }

    return howManyIncreased;
}