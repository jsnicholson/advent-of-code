#include "day1.h"
#include <assert.h>
#include <fstream>
#include <iostream>

void Day1::Parse(const char* filename, std::list<int>& lines) {
    lines.clear();
    std::ifstream file(filename);
    std::string str;
    while (std::getline(file, str))
        lines.push_back(std::stoi(str));

    assert(!lines.empty());
}

int Day1::Part1(std::list<int> numbers) {
   size_t howManyIncreased = 0;
 
   for (std::list<int>::iterator it1 = numbers.begin(), it2 = ++numbers.begin();
        it2 != numbers.end(); ++it1, ++it2) {

        if (*it2 > *it1)
            howManyIncreased++;
   }

    return howManyIncreased;
}

int Day1::Part2(std::list<int> numbers) {
    size_t howManyIncreased = 0;
    std::list<int> threeNumberWindow;
    for (std::list<int>::iterator it1 = numbers.begin(), it2 = ++numbers.begin(), it3 = ++++numbers.begin();
        it3 != numbers.end(); ++it1, ++it2, ++it3) {

        threeNumberWindow.push_back(*it1 + *it2 + *it3);
    }

    return Part1(threeNumberWindow);
}

void Day1::Run(const char* filename) {
    std::list<int> input;
    Parse(filename, input);

    std::cout << "1:" << std::to_string(Part1(input)) << std::endl;
    std::cout << "2:" << std::to_string(Part2(input)) << std::endl;
}