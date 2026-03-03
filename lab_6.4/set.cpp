#include "set.hpp"


//Нижний ригистр
std::string toLower(const std::string& str)
{
    std::string result = str;
    
    for (char& c : result)
        c = std::tolower(static_cast<unsigned char>(c));
    return result;
}
