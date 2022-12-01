#include "Day2.h"

#include <assert.h>
#include <fstream>
#include <iostream>

void Day2::Parse() {
    for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        size_t delimiter = it->find(" ");
        std::string tokenCommand = it->substr(0, delimiter);
        std::string tokenValue = it->substr(delimiter + 1);
        commands.push_back(std::make_pair(tokenCommand, std::stoi(tokenValue)));
    }
}

int Day2::Part1() {
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

int Day2::Part2() {
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