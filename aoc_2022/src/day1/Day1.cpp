#include "day1.h"

#include <algorithm>
#include <numeric>

void Day1::Parse() {
    // parse input to a vector<int> for each elf (each set of calories)
    std::vector<int> calories = {};
    for (std::vector<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        if (it->empty()) {
            m_caloriesPerElf.push_back(calories);
            calories.clear();
            continue;
        }
        
        calories.push_back(std::stoi(*it));
    }
    if (!calories.empty())
        m_caloriesPerElf.push_back(calories);
}

std::string Day1::Part1() {
    auto calories = SumEachElfsCalories();
    int result = *std::max_element(calories.begin(), calories.end());
    return std::to_string(result);
}

std::string Day1::Part2() {
    auto calories = SumEachElfsCalories();
    std::sort(calories.begin(), calories.end());

    // count last three values
    auto iterator = calories.end();
    int count = 0;
    for (int i = 0; i < 3; i++)
        count += *--iterator;

    return std::to_string(count);
}

std::vector<int> Day1::SumEachElfsCalories() { 
    std::vector<int> sums = {};
    for (std::vector<std::vector<int>>::iterator it = m_caloriesPerElf.begin(); it != m_caloriesPerElf.end(); it++) {
        auto elfCalories = *it;
        auto result = std::accumulate(elfCalories.begin(), elfCalories.end(), 0);
        sums.push_back(result);
    }
    return sums;
}