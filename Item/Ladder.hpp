/* File: Ladder.hpp */
#ifndef __LADDER_HPP__
#define __LADDER_HPP__

#include "nonTool.hpp"
#include <map>
#include <tuple>

extern map <string, tuple<int, string, string>> itemConfig;

/* Kelas LADDER */
class Ladder : public nonTool {
private:
    /* Atribut */
public:
    // Default Constructor
    Ladder() : nonTool() 
    {
    }

    // User-Defined Constructor
    Ladder(int quantity) : nonTool(get<0>(itemConfig.find("LADDER")->second), "LADDER", get<1>(itemConfig.find("LADDER")->second), quantity)
    {
    }

    // Setter

    // Getter

};

#endif