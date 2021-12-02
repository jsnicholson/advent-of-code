#include <iostream>
#include "Days.hpp"

template <typename T>
void Run() {
    std::string typeName = std::string(typeid(T).name());
    std::string dayName = typeName.substr(typeName.find(" ") + 1);

    std::cout << "Advent Of Code : " << dayName << std::endl;
    Day* day = new T();
    day->Run();
}

int main(int argc, char* argv[]) {	
	Run<Day1>();
	return 0;
}