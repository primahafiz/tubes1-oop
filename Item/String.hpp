/* File: String.hpp */
#ifndef __STRING_HPP__
#define __STRING_HPP__

#include "nonTool.hpp"
#include <map>
#include <tuple>

extern map <string, tuple<int, string, string>> itemConfig;

/* Kelas STRING */
class String : public nonTool {
private:
    /* Atribut */
public:
    // Default Constructor
    String() : nonTool() 
    {
    }

    // User-Defined Constructor
    String(int quantity) : nonTool(get<0>(itemConfig.find("STRING")->second), "STRING", get<1>(itemConfig.find("STRING")->second), quantity)
    {
    }

    // Setter

    // Getter

};

#endif