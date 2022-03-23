/* File: IronNugget.hpp */
#ifndef __IRON_NUGGET_HPP__
#define __IRON_NUGGET_HPP__

#include "nonTool.hpp"
#include <map>
#include <tuple>

extern map <string, tuple<int, string, string>> itemConfig;

/* Kelas IronNugget */
class IronNugget : public nonTool {
private:
    /* Atribut */
public:
    // Default Constructor
    IronNugget() : nonTool() 
    {
    }

    // User-Defined Constructor
    IronNugget(int quantity) : nonTool(get<0>(itemConfig.find("IRON_NUGGET")->second), "IRON_NUGGET", get<1>(itemConfig.find("IRON_NUGGET")->second), quantity)
    {
    }

    // Setter

    // Getter

};

#endif
