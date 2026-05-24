#ifdef __APPLE__
    #include <sys/ioctl.h>
    #include <termios.h>
    #include <unistd.h>
#endif
#ifdef __unix__
    #include <sys/ioctl.h>
    #include <termios.h>
    #include <unistd.h>
#endif

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include "SAL.hpp"

namespace sal {
    std::string getConfigPath() {
        std::filesystem::path configPath;
        #if defined(__unix__) || defined(__APPLE__)
            configPath = std::getenv("XDG_CONFIG_HOME") ? std::getenv("XDG_CONFIG_HOME") : "";
            if (configPath.empty()) {
                #ifdef DEBUG
                    std::cerr << sal::colorizeString("[SAL]", "38;5;11") << " " 
                              << sal::colorizeString("getConfigPath()", "38;5;14") 
                              << " - XDG_CONFIG_HOME not found" << std::endl;
                #endif
                configPath = std::getenv("HOME") ? std::getenv("HOME") : "";
                configPath /= ".config";
            }
            std::filesystem::create_directories(configPath);
        #endif
        return configPath.string();
    }

    std::string getConfigPath(std::string path) {
        std::filesystem::path configPath;
        #if defined(__unix__) || defined(__APPLE__)
            configPath = std::getenv("XDG_CONFIG_HOME") ? std::getenv("XDG_CONFIG_HOME") : "";
            if (configPath.empty()) {
                #ifdef DEBUG
                    std::cerr << sal::colorizeString("[SAL]", "38;5;11") << " " 
                              << sal::colorizeString("getConfigPath()", "38;5;14") 
                              << " - XDG_CONFIG_HOME not found" << std::endl;
                #endif
                configPath = std::getenv("HOME") ? std::getenv("HOME") : "";
                configPath /= ".config";
            }
            configPath /= path;
            std::filesystem::create_directories(configPath);
        #endif
        return configPath.string();
    }

    std::string colorizeString(std::string str, std::string colorId) {
        #if defined(__unix__) || defined(__APPLE__)
            return "\e[" + colorId + "m" + str + "\e[0m";
        #endif
	return str;
    }

    char getch() {
        termios rollback, tmp;
        char c;
        tcgetattr(0, &rollback);
        tmp = rollback;
        tmp.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(0, TCSANOW, &tmp);
        read(0, &c, 1);
        tcsetattr(0, TCSANOW, &rollback);
        return c;
    }

}
