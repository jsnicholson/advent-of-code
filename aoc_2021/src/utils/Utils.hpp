#pragma once
#include <list>
#include <string>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <iomanip>

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
};