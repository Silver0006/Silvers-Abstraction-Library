#ifndef SILVERS_ABSTRACTION_LIBRARY
#define SILVERS_ABSTRACTION_LIBRARY

#include <string>

namespace sal{
   
    std::string getConfigPath(); /// Returns path to OS directory for application config
    std::string getConfigPath(std::string);

    std::string colorizeString(std::string, std::string); /// Applies ansi code to std::string "\e[" + colorId + "m" + str + "\e[0m"

    char getch();

}

#endif
