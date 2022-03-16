/* File: IronNugget.hpp */
#ifndef __IRON_NUGGET_HPP__
#define __IRON_NUGGET_HPP__

#include "nonTool.hpp"

/* Kelas IronNugget */
class IronNugget : public nonTool {
private:
    /* Atribut */
public:
    // Default Constructor
    IronNugget() : nonTool() {
 
    }

    // User-Defined Constructor
    IronNugget() : nonTool(11, "IRON_NUGGET", "-", 0) {
    }

    // Setter

    // Getter

};

#endif
