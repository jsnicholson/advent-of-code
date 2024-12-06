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
#include <iostream>
#include <regex>
#include <map>

#include "Days.hpp"

class Utils {
public:
	static bool ReadFile(const std::string filename, std::vector<std::string>& data) {
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

    template<typename T>
    static const std::string DayTypeToInputFilename() {
        const std::string typeName = std::string(typeid(T).name());
        const std::string dayName = typeName.substr(typeName.find(" ") + 1);
        const std::string inputfilename = std::string("resources\\input_") + Utils::ToLower(dayName) + std::string(".txt");
        return inputfilename;
    }

    template <typename T>
    static void RunDay() {
        const std::string typeName = std::string(typeid(T).name());
        const std::string dayName = typeName.substr(typeName.find(" ") + 1);

        std::cout << "Opening " << dayName << "..." << std::endl;

        Day* day = new T();

        std::string inputfilename;
        if ((inputfilename = day->GetInput()).empty())
            inputfilename = DayTypeToInputFilename<T>();

        day->Run(inputfilename);
        delete day;
    }

    static void OpenDay(const size_t day) {
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

    static std::vector<std::string> Split(std::string string, std::string delimiter) {
        std::vector<std::string> splits{};
        size_t pos = 0;
        std::string token;
        while ((pos = string.find(delimiter)) != std::string::npos) {
            token = string.substr(0, pos);
            splits.push_back(token);
            string.erase(0, pos + delimiter.length());
        }
        splits.push_back(string);
        return splits;
    }

    static std::vector<std::string> Split(std::string string, char delimiter) {
        std::vector<std::string> splits{};
        size_t pos = 0;
        std::string token;
        while ((pos = string.find(delimiter)) != std::string::npos) {
            token = string.substr(0, pos);
            splits.push_back(token);
            string.erase(0, pos + 1);
        }
        splits.push_back(string);
        return splits;
    }

    static std::vector<std::string> SplitOnWhitespace(std::string input) {
        std::regex whitespaceRegex("\\s+");
        std::sregex_token_iterator iter(input.begin(), input.end(), whitespaceRegex, -1);
        std::sregex_token_iterator end;

        std::vector<std::string> tokens(iter, end);

        tokens.erase(std::remove_if(tokens.begin(), tokens.end(),
            [](const std::string& s) { return s.empty(); }),
            tokens.end());

        return tokens;
    }

    static void StringReplace(std::string& str, char characterToReplace, char characterToPlace) {
        size_t found = str.find(characterToReplace);
        while (found != std::string::npos) {
            str.replace(found,1,std::string{characterToPlace});
            found = str.find(characterToReplace, found + 1);
        }
    }

    static void StringReplace(std::string& str, char characterToReplace, std::string stringToPlace) {
        size_t found = str.find(characterToReplace);
        while (found != std::string::npos) {
            str.replace(found, 1, stringToPlace);
            found = str.find(characterToReplace, found + stringToPlace.length());
        }
    }

    static void StringReplace(std::string& str, std::string stringToReplace, char characterToPlace) {
        size_t found = str.find(stringToReplace);
        while (found != std::string::npos) {
            str.replace(found,stringToReplace.length(), std::string{characterToPlace});
            found = str.find(stringToReplace, found + 1);
        }
    }

    static void StringReplace(std::string& str, std::string stringToReplace, std::string stringToPlace) {
        size_t found = str.find(stringToReplace);
        while (found != std::string::npos) {
            str.replace(found, stringToReplace.length(), stringToPlace);
            found = str.find(stringToReplace, found + stringToPlace.length());
        }
    }

    template <typename Key, typename Value, typename Predicate>
    std::vector<Key> Where(std::map<Key, Value> container, Predicate predicate) {
        std::vector<Key> result;
        std::copy_if(container.begin(), container.end(), std::back_inserter(result), predicate);
        return result;
    }

    static std::pair<int, int> add(std::pair<int, int> a, int b) {
        return std::pair<int, int>{a.first + b, a.second + b};
    }

    static std::pair<int, int> add(std::pair<int, int> a, std::pair<int, int> b) {
        return std::pair<int, int>{a.first + b.first, a.second + b.second};
    }

    static std::pair<int, int> subtract(std::pair<int, int> a, int b) {
        return std::pair<int, int>{a.first - b, a.second - b};
    }

    static std::pair<int, int> subtract(std::pair<int, int> a, std::pair<int, int> b) {
        return std::pair<int, int>{a.first - b.first, a.second - b.second};
    }

    template <typename T>
    static std::pair<T, T> multiply(std::pair<T, T> a, T b) {
        return std::pair<T, T>{a.first * b, a.second * b};
    }

    template <typename T>
    static std::pair<T, T> multiply(std::pair<T, T> a, std::pair<T,T> b) {
        return std::pair<T, T>{a.first * b.second, a.second * b.second};
    }

    template <typename T>
    static bool contains(std::vector<T> v, T i) {
        return std::find(v.begin(), v.end(), i) != v.end();
    }

    static std::vector<size_t> FindAll(std::string str, char item) {
        std::vector<size_t> vecFound = {};
        size_t pos = str.find(item, 0);
        while (pos != std::string::npos) {
            vecFound.push_back(pos);
            pos = str.find(item, pos + 1);
        }
        return vecFound;
    }

    static std::vector<size_t> FindAll(std::string str, std::string sub) {
        std::vector<size_t> vecFound = {};
        size_t pos = str.find(sub, 0);
        while (pos != std::string::npos) {
            vecFound.push_back(pos);
            pos = str.find(sub, pos + 1);
        }
        return vecFound;
    }

    static std::vector<std::pair<size_t, size_t>> FindAll(std::vector<std::string> container, char c) {
        std::vector<std::pair<size_t,size_t>> vecFound = {};
        for (std::vector<std::string>::iterator it = container.begin(); it != container.end(); it++) {
            size_t rowIndex = std::distance(container.begin(), it);
            auto b = FindAll(*it, c);
            for (const auto i : b)
                vecFound.push_back(std::make_pair(rowIndex,i));
        }
        return vecFound;
    }

    static std::vector<std::string> FindAll(std::string text, std::regex pattern) {
        std::vector<std::string> matches;

        for (std::sregex_iterator it = std::sregex_iterator(text.begin(), text.end(), pattern); it != std::sregex_iterator(); it++) {
            matches.push_back(it->str());
        }

        return matches;
    }

    static std::vector<int> ToVectorInt(std::vector<std::string> vectorString) {
        std::vector<int> vectorInt;

        for (std::vector<std::string>::iterator it = vectorString.begin(); it != vectorString.end(); it++) {
            vectorInt.push_back(std::stoi(*it));
        }

        return vectorInt;
    }
};