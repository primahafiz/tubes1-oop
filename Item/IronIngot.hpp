/* File: IronIngot.hpp */
#ifndef __IRON_INGOT_HPP__
#define __IRON_INGOT_HPP__

#include "nonTool.hpp"
#include <map>
#include <tuple>

extern map <string, tuple<int, string, string>> itemConfig;

/* Kelas IronIngot */
class IronIngot : public nonTool {
private:
    /* Atribut */
public:
    // Default Constructor
    IronIngot() : nonTool() 
    {
    }

    // User-Defined Constructor
    IronIngot(int quantity) : nonTool(get<0>(itemConfig.find("IRON_INGOT")->second), "IRON_INGOT", get<1>(itemConfig.find("IRON_INGOT")->second), quantity)
    {
    }

    // Setter

    // Getter

};

#endif