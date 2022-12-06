#include "Day6.h"

#include <queue>
#include <set>
#include <cmath>

void Day6::Parse() {
    m_signal = data.front();
}

std::string Day6::Part1() {
    int indexOfPacketMarker = 0;
    std::string buffer;
    for (std::string::iterator it = m_signal.begin(); it != m_signal.end(); it++) {
        buffer.push_back(*it);
        if (buffer.length() > 4) {
            buffer.erase(0, 1);
        }
        if (buffer.length() == 4) {
            if (StringHasNoDuplicates(buffer)) {
                indexOfPacketMarker = abs(std::distance(it, m_signal.begin())) + 1;
                break;
            }
        }
    }
    return std::to_string(indexOfPacketMarker);
}

std::string Day6::Part2() {
    int markerLength = 14;
    int indexOfPacketMarker = 0;
    std::string buffer;
    for (std::string::iterator it = m_signal.begin(); it != m_signal.end(); it++) {
        buffer.push_back(*it);
        if (buffer.length() > markerLength) {
            buffer.erase(0, 1);
        }
        if (buffer.length() == markerLength) {
            if (StringHasNoDuplicates(buffer)) {
                indexOfPacketMarker = abs(std::distance(it, m_signal.begin())) + 1;
                break;
            }
        }
    }
    return std::to_string(indexOfPacketMarker);
}

bool Day6::StringHasNoDuplicates(std::string string) {
    std::set<char> check_uniq;
    for (unsigned long int i = 0; i < string.length(); ++i)
        if (!check_uniq.insert(string[i]).second)
            return false; // Duplicated char found
    return true; // No duplicated char found
}