#ifndef SILVERS_ABSTRACTION_LIBRARY
#define SILVERS_ABSTRACTION_LIBRARY

#include <string>

namespace sal{
   
    std::string getConfigPath(); /// Returns path to OS directory for application config
    std::string getConfigPath(std::string);

}

#endif
