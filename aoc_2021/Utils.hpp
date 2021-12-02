#pragma once
#include <list>
#include <string>
#include <fstream>
#include <assert.h>
#include <iostream>

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

    template <typename T>
    static void Run() {
        std::string typeName = std::string(typeid(T).name());
        std::string dayName = typeName.substr(typeName.find(" ") + 1);

        std::cout << "Advent Of Code : " << dayName << std::endl;
        Day* day = new T();
        day->Run();
    }
};