#pragma once
#include <list>
#include <string>
#include <fstream>
#include <assert.h>

static class Utils {
public:
	static void ReadFile(const char* filename, std::list<std::string>& data) {
        data.clear();
        std::ifstream file(filename);
        std::string str;
        while (std::getline(file, str))
            data.push_back(str);

        assert(!data.empty());
	}
};