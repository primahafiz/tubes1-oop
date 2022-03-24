/* File: FishingRod.hpp */
#ifndef __FISHING_ROD_HPP__
#define __FISHING_ROD_HPP__

#include "Tool.hpp"
#include <map>
#include <tuple>

extern map <string, tuple<int, string, string>> itemConfig;

/* Kelas FishingRod */
class FishingRod : public Tool {
private:
    /* Atribut */
public:
    // Default Constructor
    FishingRod() : Tool() {
    }

    // User-Defined Constructor
    FishingRod(int durability) : Tool(get<0>(itemConfig.find("FISHING_ROD")->second), "FISHING_ROD", get<1>(itemConfig.find("FISHING_ROD")->second), 10){
    }

    // Setter

    // Getter

};

#endif