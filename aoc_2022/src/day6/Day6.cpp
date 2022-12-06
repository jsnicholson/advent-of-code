#include "Day6.h"

#include <queue>
#include <set>
#include <cmath>

void Day6::Parse() {
    m_signal = data.front();
}

std::string Day6::Part1() {
    return std::to_string(FindFirstUniqueStringOfLengthN(m_signal, 4));
}

std::string Day6::Part2() {
    return std::to_string(FindFirstUniqueStringOfLengthN(m_signal, 14));
}

bool Day6::StringHasDuplicates(std::string string) {
    std::set<char> check_uniq;
    for (unsigned long int i = 0; i < string.length(); ++i)
        if (!check_uniq.insert(string[i]).second)
            return true; // Duplicated char found
    return false; // No duplicated char found
}

int Day6::FindFirstUniqueStringOfLengthN(std::string string, int length) {
    int indexOfUniqueString = 0;
    std::string buffer;
    for (std::string::iterator it = string.begin(); it != string.end(); it++) {
        buffer.push_back(*it);
        if (buffer.length() > length) {
            buffer.erase(0, 1);
        }
        if (buffer.length() == length) {
            if (!StringHasDuplicates(buffer)) {
                indexOfUniqueString = abs(std::distance(it, string.begin())) + 1;
                break;
            }
        }
    }
    return indexOfUniqueString;
}