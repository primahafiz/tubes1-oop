/* File: Diamond.hpp */
#ifndef __DIAMOND_HPP__
#define __DIAMOND_HPP__

#include "nonTool.hpp"
#include <map>
#include <tuple>

extern map <string, tuple<int, string, string>> itemConfig;

/* Kelas Diamond */
class Diamond : public nonTool
{
private:
    /* Atribut */
public:
    // Default Constructor
    Diamond() : nonTool()
    {
    }

    // User-Defined Constructor
    Diamond(int quantity) : nonTool(get<0>(itemConfig.find("DIAMOND")->second), "DIAMOND", get<1>(itemConfig.find("DIAMOND")->second), quantity)
    {
    }

    // Setter

    // Getter
};

#endif