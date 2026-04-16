#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include "SAL.hpp"

namespace sal {

    std::string getConfigPath(){
        std::filesystem::path configPath;
        #ifdef __linux__
            configPath = std::getenv("XDG_CONFIG_HOME") ? std::getenv("XDG_CONFIG_HOME") : "";
            if (configPath.empty()) {
                #ifdef DEBUG
                    std::cerr << "\e[38;5;11m[SAL]\e[0m \e[38;5;14mgetConfigPath()\e[0m - XDG_CONFIG_HOME not found" << std::endl;
                #endif
                configPath = std::getenv("HOME") ? std::getenv("HOME") : "";
                configPath /= ".config";
            }
            std::filesystem::create_directories(configPath);
        #endif
        return configPath.string();
    }

    std::string getConfigPath(std::string path){
        std::filesystem::path configPath;
        #ifdef __linux__
            configPath = std::getenv("XDG_CONFIG_HOME") ? std::getenv("XDG_CONFIG_HOME") : "";
            if (configPath.empty()) {
                #ifdef DEBUG
                    std::cerr << "\e[38;5;11m[SAL]\e[0m \e[38;5;14mgetConfigPath()\e[0m - XDG_CONFIG_HOME not found" << std::endl;
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
        #ifdef __linux__
            return "\e[" + colorId + str + "\e[0m";
        #endif
    }

}
