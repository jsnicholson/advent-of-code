#include <iostream>

#include "Days.hpp"

const char* banner = R"(
              _                 _            __    _____          _      
     /\      | |               | |          / _|  / ____|        | |     
    /  \   __| |_   _____ _ __ | |_    ___ | |_  | |     ___   __| | ___ 
   / /\ \ / _` \ \ / / _ \ '_ \| __|  / _ \|  _| | |    / _ \ / _` |/ _ \
  / ____ \ (_| |\ V /  __/ | | | |_  | (_) | |   | |___| (_) | (_| |  __/
 /_/    \_\__,_| \_/ \___|_| |_|\__|  \___/|_|    \_____\___/ \__,_|\___|

       .-.                                                   \ /
      ( (                                |                  - * -
       '-`                              -+-                  / \
                \            o          _|_          \
                ))          }^{        /___\         ))
              .-#-----.     /|\     .---'-'---.    .-#-----.
         ___ /_________\   //|\\   /___________\  /_________\  
        /___\ |[] _ []|    //|\\    | A /^\ A |    |[] _ []| _.O,_
    ....|"#"|.|  |*|  |...///|\\\...|   |"|   |....|  |*|  |..(^).... )";

template <typename T>
void RunDay() {
    std::string typeName = std::string(typeid(T).name());
    std::string dayName = typeName.substr(typeName.find(" ") + 1);

    std::cout << "Opening " << dayName << "..." << std::endl;
    Day* day = new T();
    day->Run();
}

void OpenDay(int day) {
    switch (day) {
    case 1:
        RunDay<Day1>();break;
    case 2:
        RunDay<Day2>();break;
    case 3:
        RunDay<Day3>();break;
    case 4:
        RunDay<Day4>();break;
    case 5:
        RunDay<Day5>();break;
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

int main(int argc, char* argv[]) {
    std::cout << banner << "\n\n" << std::endl;

    int day;
    std::cout << "Which day are you opening?" << std::endl;
    std::cin >> day;

    OpenDay(day);

	return 0;
}