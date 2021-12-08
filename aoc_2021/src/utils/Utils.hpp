#pragma once
#include <list>
#include <string>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <vector>
#include <numeric>

#include "Days.hpp"

class Utils {
public:
	static bool ReadFile(std::string filename, std::list<std::string>& data) {
        data.clear();
        std::ifstream file(filename.c_str());
        std::string str;
        while (std::getline(file, str))
            data.push_back(str);

        if (data.empty()) {
            std::cout << "No data found at " << std::quoted(filename) << std::endl;
            return false;
        }

        return true;
	}

    static std::string ToLower(std::string str) {
        std::string strLower = str;
        std::transform(strLower.begin(), strLower.end(), strLower.begin(), ::tolower);
        return strLower;
    }

    template <typename T>
    static void RunDay() {
        std::string typeName = std::string(typeid(T).name());
        std::string dayName = typeName.substr(typeName.find(" ") + 1);

        std::cout << "Opening " << dayName << "..." << std::endl;

        Day* day = new T();

        std::string inputfilename;
        if((inputfilename = day->GetInput()).empty())
            inputfilename = std::string("resources\\input_") + Utils::ToLower(dayName) + std::string(".txt");

        day->Run(inputfilename);
    }

    static void SplitStringIntoVector(std::vector<int>& vector, const std::string data, const char delimiter) {
        std::istringstream iss(data);
        std::string item;
        while (std::getline(iss, item, delimiter)) {
            if (item.empty())
                continue;
            vector.push_back(std::stoi(item));
        }
    }


    static int SumBoard(std::vector<std::vector<std::pair<int, bool>>> all) {
        int sum = 0;
        for (const auto& line : all) {
            for (const auto& entry : line)
                sum += entry.first;
        }
        return sum;
    }

    static void OpenDay(int day) {
        switch (day) {
        case 1:
            RunDay<Day1>(); break;
        case 2:
            RunDay<Day2>(); break;
        case 3:
            RunDay<Day3>(); break;
        case 4:
            RunDay<Day4>(); break;
        case 5:
            RunDay<Day5>(); break;
        case 6:
            RunDay<Day6>(); break;
        case 7:
            RunDay<Day7>(); break;
        case 8:
            RunDay<Day8>(); break;
        case 9:
            RunDay<Day9>(); break;
        case 10:
            RunDay<Day10>(); break;
        case 11:
            RunDay<Day11>(); break;
        case 12:
            RunDay<Day12>(); break;
        case 13:
            RunDay<Day13>(); break;
        case 14:
            RunDay<Day14>(); break;
        case 15:
            RunDay<Day15>(); break;
        case 16:
            RunDay<Day16>(); break;
        case 17:
            RunDay<Day17>(); break;
        case 18:
            RunDay<Day18>(); break;
        case 19:
            RunDay<Day19>(); break;
        case 20:
            RunDay<Day20>(); break;
        case 21:
            RunDay<Day21>(); break;
        case 22:
            RunDay<Day22>(); break;
        case 23:
            RunDay<Day23>(); break;
        case 24:
            RunDay<Day24>(); break;
        case 25:
            RunDay<Day25>(); break;
        default:
            std::cout << "That day isnt in the advent!" << std::endl;
        }
    }
};