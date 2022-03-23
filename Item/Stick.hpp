/* File: Stick.hpp */
#ifndef __STICK_HPP__
#define __STICK_HPP__

#include "nonTool.hpp"
#include <map>
#include <tuple>

extern map <string, tuple<int, string, string>> itemConfig;

/* Kelas Stick */
class Stick : public nonTool {
private:
    /* Atribut */
public:
    // Default Constructor
    Stick() : nonTool()
    {
    }

    // User-Defined Constructor
    Stick(int quantity) : nonTool(get<0>(itemConfig.find("STICK")->second), "STICK", get<1>(itemConfig.find("STICK")->second), quantity)
    {
    }

    // Setter

    // Getter

};

#endif