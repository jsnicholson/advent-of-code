#include "day1.h"

#include <algorithm>
#include <numeric>

void Day1::Parse() {
    m_lines = data;
}

std::string Day1::Part1() {
    std::vector<char> vectorCalibrationValues = {};
    for (std::vector<std::string>::iterator it = m_lines.begin(); it != m_lines.end(); it++) {
        std::string line = *it;
        int indexFirstDigit = FindFirstDigit(line);
        int indexLastDigit = FindLastDigit(line);
        vectorCalibrationValues.push_back(std::stoi(std::string{line[indexFirstDigit], line[indexLastDigit]}));
    }
    return std::to_string(std::accumulate(vectorCalibrationValues.begin(), vectorCalibrationValues.end(), 0));
}

std::string Day1::Part2() {

    return std::to_string(0);
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