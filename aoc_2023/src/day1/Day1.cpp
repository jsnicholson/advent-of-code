#include "day1.h"

#include <algorithm>
#include <numeric>

#include "Utils.hpp"

void Day1::Parse() {
    m_lines = data;
}

std::string Day1::Part1() {
    std::vector<int> vectorCalibrationValues = {};
    for (std::vector<std::string>::iterator it = m_lines.begin(); it != m_lines.end(); it++) {
        std::string line = *it;
        int indexFirstDigit = FindFirstDigit(line);
        int indexLastDigit = FindLastDigit(line);
        vectorCalibrationValues.push_back(std::stoi(std::string{line[indexFirstDigit], line[indexLastDigit]}));
    }
    return std::to_string(std::accumulate(vectorCalibrationValues.begin(), vectorCalibrationValues.end(), 0));
}

std::string Day1::Part2() {
    std::map<std::string, int> mapStringToInt = { {"one",1}, {"two",2}, {"three",3}, {"four",4}, {"five",5}, {"six",6}, {"seven",7}, {"eight",8}, {"nine",9} };
    std::vector<int> vectorCalibrationValues = {};
    for (std::vector<std::string>::iterator it = m_lines.begin(); it != m_lines.end(); it++) {
        std::string line = *it;

        int numberFirst = 0, numberLast = 0;
        int numberFirstIndex = std::string::npos, numberLastIndex = std::string::npos;
        for (const auto& [key, value] : mapStringToInt) {
            size_t f = line.find(key);
            size_t l = line.rfind(key);
            if (f != std::string::npos && f < numberFirstIndex) {
                numberFirstIndex = f;
                numberFirst = value;
            }
            if (l != std::string::npos && (l > numberLastIndex || numberLastIndex == std::string::npos)) {
                numberLastIndex = l;
                numberLast = value;
            }
        }
        size_t fd = FindFirstDigit(line);
        size_t fl = FindLastDigit(line);
        if (fd != std::string::npos && fd < numberFirstIndex) {
            numberFirstIndex = fd;
            numberFirst = line[numberFirstIndex] - '0';
        }
        if (fl != std::string::npos && (fl > numberLastIndex || numberLastIndex == std::string::npos)) {
            numberLastIndex = fl;
            numberLast = line[numberLastIndex] - '0';
        }

        vectorCalibrationValues.push_back(std::stoi(std::to_string(numberFirst) + std::to_string(numberLast)));
    }
    return std::to_string(std::accumulate(vectorCalibrationValues.begin(), vectorCalibrationValues.end(), 0));
}

size_t Day1::FindFirstDigit(std::string line) {
    std::string::iterator it = line.begin();

    while (it != line.end()) {
        char c = *it;
        if (std::isdigit(c))
            return it - line.begin();
        it++;
    }

    return std::string::npos;
}

size_t Day1::FindLastDigit(std::string line) {
    std::string::reverse_iterator rit = line.rbegin();

    while (rit != line.rend()) {
        char c = *rit;
        if (std::isdigit(c))
            return line.length() - (rit - line.rbegin()) - 1;
        rit++;
    }

    return std::string::npos;
}