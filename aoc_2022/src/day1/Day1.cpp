#include "day1.h"

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
    return -1;
}

int Day1::Part2() {
    return -1;
}