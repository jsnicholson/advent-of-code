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
void Run() {
    std::cout << banner << "\n\n" << std::endl;

    std::string typeName = std::string(typeid(T).name());
    std::string dayName = typeName.substr(typeName.find(" ") + 1);

    std::cout << "Opening " << dayName << "..." << std::endl;
    Day* day = new T();
    day->Run();
}

void PrintBanner() {
    std::cout << banner << std::endl;

}

int main(int argc, char* argv[]) {	
	Run<Day1>();
	return 0;
}