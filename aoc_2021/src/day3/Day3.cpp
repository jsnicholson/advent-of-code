#include "Day3.h"

#include <assert.h>
#include <fstream>
#include <iostream>

void Day3::Parse() {
    for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        listBitset.push_back(std::bitset<bitsetLength>(*it));
    }
}

int Day3::Part1() {
    int total = 0;
    std::bitset<bitsetLength> gamma{ "" }, epsilon{ "" };

    for (int i = 0; i < bitsetLength; i++) {
        total = 0;

        for (const auto& bitset : listBitset) {
            total += (bitset[i]) ? 1 : -1;
        }

        gamma.set(i, total >= 0);
        epsilon.set(i, total < 0);
    }

    return static_cast<int>(gamma.to_ulong()) * static_cast<int>(epsilon.to_ulong());
}

int Day3::Part2() {
    return -1;
}