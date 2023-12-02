#include "day1.h"

#include <algorithm>
#include <numeric>

void Day1::Parse() {
    m_lines = data;
}

std::string Day1::Part1() {
    std::vector<int> vectorCalibrationValues = {};
    for (std::vector<std::string>::iterator it = m_lines.begin(); it != m_lines.end(); it++) {
        std::string line = *it;
        std::pair<char, char> pairCalibrationValues = FindFirstAndLastDigit(line);
        vectorCalibrationValues.push_back(std::stoi(std::string{pairCalibrationValues.first,pairCalibrationValues.second}));
    }
    return std::to_string(std::accumulate(vectorCalibrationValues.begin(), vectorCalibrationValues.end(), 0));
}

std::string Day1::Part2() {

    return std::to_string(0);
}

std::pair<char, char> Day1::FindFirstAndLastDigit(std::string line) {
    std::pair<char, char> digits;
    std::string::iterator it = line.begin();
    std::string::reverse_iterator rit = line.rbegin();

    while (it != line.end()) {
        char c = *it;
        if (std::isdigit(c)) {
            digits.first = c;
            it = line.end();
            continue;
        }

        it++;
    }

    while (rit != line.rend()) {
        char c = *rit;
        if (std::isdigit(c)) {
            digits.second = c;
            rit = line.rend();
            continue;
        }

        rit++;
    }
    
    return digits;
}