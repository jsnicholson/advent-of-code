#include "day1.h"

#include <algorithm>

void Day1::Parse() {
    int calorie = 0;
    for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        if (it->empty()) {
            calories.push_back(calorie);
            calorie = 0;
        }
        else {
            calorie += std::stoi(*it);
        }
    }
    if (calorie > 0)
        calories.push_back(calorie);
}

int Day1::Part1() {
    return *std::max_element(calories.begin(), calories.end());
}

int Day1::Part2() {
    calories.sort();
    auto iterator = calories.end();
    int count = 0;
    for (int i = 0; i < 3; i++)
        count += *--iterator;
    return count;
}