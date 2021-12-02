#include "day2.h"
#include <assert.h>
#include <fstream>
#include <iostream>

void Day2::Parse(const char* filename, list_commands& parsed) {
    parsed.clear();

    // read file
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        size_t delimiter = line.find(" ");
        std::string tokenCommand = line.substr(0, delimiter);
        std::string tokenValue = line.substr(delimiter + 1);
        parsed.push_back(std::make_pair(tokenCommand, std::stoi(tokenValue)));
    }
}

int Day2::Part1(list_commands commands) {
    int position = 0, depth = 0;
    for (list_commands::iterator it1 = commands.begin(); it1 != commands.end(); it1++) {
        std::string command = it1->first;
        int value = it1->second;
        
        if (command == "forward") {
            position += value;
        }
        else if (command == "up") {
            depth -= value;
        }
        else if (command == "down") {
            depth += value;
        }
    }
    return position*depth;
}

int Day2::Part2(list_commands commands) {
    int position = 0, aim = 0, depth = 0;
    for (list_commands::iterator it1 = commands.begin(); it1 != commands.end(); it1++) {
        std::string command = it1->first;
        int value = it1->second;

        if (command == "forward") {
            position += value;
            depth += aim * value;
        }
        else if (command == "up") {
            aim -= value;
        }
        else if (command == "down") {
            aim += value;
        }
    }
    return position * depth;
}


void Day2::Run(const char* filename) {
    list_commands input;
    Parse(filename, input);

    std::cout << "1:" << std::to_string(Part1(input)) << std::endl;
    std::cout << "2:" << std::to_string(Part2(input)) << std::endl;
}