#include <iostream>

#include "Utils.hpp"

const char* banner = R"(
                     ___     ___    ___    ____  
                    |__ \   / _ \  |__ \  |___ \ 
                       ) | | | | |    ) |   __) |
                      / /  | | | |   / /   |__ < 
                     / /_  | |_| |  / /_   ___) |
                    |____|  \___/  |____| |____/ 
                                      
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

int main(int argc, char* argv[]) {
    std::cout << banner << "\n\n" << std::endl;

    int day;
    std::cout << "Which day are you opening? ";
    std::cin >> day;

    Utils::OpenDay(day);

	return 0;
}