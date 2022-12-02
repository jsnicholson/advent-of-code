#include "day1.h"

#include <algorithm>
#include <numeric>

void Day1::Parse() {
    // parse input to a vector<int> for each elf (each set of calories)
    std::vector<int> calories = {};
    for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        if (it->empty()) {
            m_vecCaloriesPerElf.push_back(calories);
            calories.clear();
            continue;
        }
        
        calories.push_back(std::stoi(*it));
    }
    if (!calories.empty())
        m_vecCaloriesPerElf.push_back(calories);
}

int Day1::Part1() {
    auto calories = SumEachElfsCalories();
    return *std::max_element(calories.begin(), calories.end());
}

int Day1::Part2() {
    auto calories = SumEachElfsCalories();
    std::sort(calories.begin(), calories.end());

    // count last three values
    auto iterator = calories.end();
    int count = 0;
    for (int i = 0; i < 3; i++)
        count += *--iterator;

    return count;
}

std::vector<int> Day1::SumEachElfsCalories() { 
    std::vector<int> sums = {};
    for (std::vector<std::vector<int>>::iterator it = m_vecCaloriesPerElf.begin(); it != m_vecCaloriesPerElf.end(); it++) {
        auto elfCalories = *it;
        auto result = std::accumulate(elfCalories.begin(), elfCalories.end(), 0);
        sums.push_back(result);
    }
    return sums;
}