#pragma once
#include <list>
#include <string>
#include <fstream>
#include <assert.h>
#include <algorithm>

class Utils {
public:
	static void ReadFile(std::string filename, std::list<std::string>& data) {
        data.clear();
        std::ifstream file(filename.c_str());
        std::string str;
        while (std::getline(file, str))
            data.push_back(str);

        assert(!data.empty());
	}

    static std::string ToLower(std::string str) {
        std::string strLower = str;
        std::transform(strLower.begin(), strLower.end(), strLower.begin(), ::tolower);
        return strLower;
    }
};