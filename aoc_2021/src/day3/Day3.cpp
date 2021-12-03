#include "Day3.h"

#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "Utils.hpp"

void Day3::Parse() {
    for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        listBitset.push_back(std::bitset<bitsetLength>(*it));
    }
}

int Day3::Part1() {
    std::bitset<bitsetLength> gamma{ "" }, epsilon{ "" };

    for (int i = 0; i < bitsetLength; i++) {
        int mostcommon = MostCommonBitInPosition(i, listBitset);

        gamma.set(i, mostcommon >= 0);
        epsilon.set(i, mostcommon < 0);
    }

    // convert both to ints and multiply for final answer
    return static_cast<int>(gamma.to_ulong()) * static_cast<int>(epsilon.to_ulong());
}

int Day3::Part2() {
    std::bitset<bitsetLength> oxygen{ "" }, co2{ "" };
    std::list<std::bitset<bitsetLength>> oxygenCandidates = listBitset, co2Candidates = listBitset;

    // bitset is actually stored backwards so we need to traverse backwards
    for (int i = bitsetLength - 1; i >= 0; i--) {

        if (oxygenCandidates.size() > 1) {
            int mostcommon = MostCommonBitInPosition(i, oxygenCandidates);
            //prune
            oxygenCandidates.erase(std::remove_if(oxygenCandidates.begin(), oxygenCandidates.end(), [&](std::bitset<bitsetLength> bitset) { 
                return !(bitset[i] == (mostcommon >= 0)); 
            }), oxygenCandidates.end());
        }
        if (co2Candidates.size() > 1) {
            int mostcommon = MostCommonBitInPosition(i, co2Candidates);
            //prune
            co2Candidates.erase(std::remove_if(co2Candidates.begin(), co2Candidates.end(), [&](std::bitset<bitsetLength> bitset) { 
                return !(bitset[i] == (mostcommon < 0)); 
            }), co2Candidates.end());
        }
        // take final values
        if (oxygenCandidates.size() == 1 && co2Candidates.size() == 1) {
            oxygen = oxygenCandidates.front();
            co2 = co2Candidates.front();
            break;
        }    
    }

    // convert both to ints and multiply for final answer
    return static_cast<int>(oxygen.to_ulong()) * static_cast<int>(co2.to_ulong());
}

// returns a value that if negative, 0 is more common, if positive, 1 is more common, if 0 both the same
int Day3::MostCommonBitInPosition(size_t position, std::list<std::bitset<bitsetLength>> list) {
    int total = 0;
    for (const auto& bitset : list) {
        // + or - to even out how many
        total += (bitset[position] ? 1 : -1);
    }
    return total;
}
