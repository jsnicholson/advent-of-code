#include "Day4.h"
#include "Utils.hpp"

void Day4::Parse() {
    for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        std::string line = *it;
        int indexOfPairDelimiter = line.find(',');
        std::string rawFirstRange = line.substr(0, indexOfPairDelimiter);
        std::string rawSecondRange = line.substr(indexOfPairDelimiter+1);
        int indexOfFirstRangeDelimiter = rawFirstRange.find('-');
        range firstRange = std::make_pair(std::stoi(rawFirstRange.substr(0, indexOfFirstRangeDelimiter)), std::stoi(rawFirstRange.substr(indexOfFirstRangeDelimiter+1))); 
        int indexOfSecondRangeDelimiter = rawSecondRange.find('-');
        range secondRange = std::make_pair(std::stoi(rawSecondRange.substr(0, indexOfSecondRangeDelimiter)), std::stoi(rawSecondRange.substr(indexOfSecondRangeDelimiter+1)));
        m_pairsOfCleaningRanges.push_back(std::make_pair(firstRange, secondRange));
    }
}

int Day4::Part1() {
    int countHowManyRangesFullyContainTheOtherRangeInItsPair = 0;
    for (std::list<rangepair>::iterator it = m_pairsOfCleaningRanges.begin(); it != m_pairsOfCleaningRanges.end(); it++) {
        rangepair rangepair = *it;
        if ((rangepair.first.first <= rangepair.second.first && rangepair.first.second >= rangepair.second.second) ||
            (rangepair.second.first <= rangepair.first.first && rangepair.second.second >= rangepair.first.second))
            countHowManyRangesFullyContainTheOtherRangeInItsPair++;
    }
    return countHowManyRangesFullyContainTheOtherRangeInItsPair;
}

int Day4::Part2() {
    int countHowManyRangesOverlap = 0;
    for (std::list<rangepair>::iterator it = m_pairsOfCleaningRanges.begin(); it != m_pairsOfCleaningRanges.end(); it++) {
        rangepair rangepair = *it;
        if ((rangepair.first.first >= rangepair.second.first && rangepair.first.first <= rangepair.second.second) ||
            (rangepair.first.second >= rangepair.second.first && rangepair.first.second <= rangepair.second.second) ||
            (rangepair.second.first >= rangepair.first.first && rangepair.second.first <= rangepair.first.second) ||
            (rangepair.second.second >= rangepair.first.first && rangepair.second.second <= rangepair.first.second))
            countHowManyRangesOverlap++;
    }
    return countHowManyRangesOverlap;
}