#include <iostream>
#include "include/SAL.hpp"

int main(){
    std::cout << sal::colorizeString("getConfigPath()", "38;5;162") << " - "
              << sal::colorizeString(sal::getConfigPath(), "38;2;160;32;255") << "\n"
              << sal::colorizeString("getConfigPath(std::string)", "38;5;162") << " - "
              << sal::colorizeString(sal::getConfigPath("wowzzer"), "38;2;160;32;255")
              << std::endl;
        
    std::cout << "testing " << sal::colorizeString("getch(): ", "38;5;162") 
              << std::flush << sal::getch() << std::endl;

    return 0;
}
