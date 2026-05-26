#ifndef SILVERS_ABSTRACTION_LIBRARY
#define SILVERS_ABSTRACTION_LIBRARY

#include <string>

namespace sal{
   
    /// Returns path to OS default directory for application config
    /// bool == create if not exist
    /// string gets tagged on to the config path
    std::string getConfigPath(const std::string = "", const bool = false);

    std::string colorizeString(std::string, std::string); /// Applies ansi code to std::string "\e[" + colorId + "m" + str + "\e[0m"

    char getch();

}

#endif
