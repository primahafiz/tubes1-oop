/* File: IronNugget.hpp */
#ifndef __IRON_NUGGET_HPP__
#define __IRON_NUGGET_HPP__

#include "nonTool.hpp"

/* Kelas IronNugget */
class IronNugget : public nonTool {
private:
    /* Atribut */
    int quantity;
public:
    // Default Constructor
    IronNugget() : nonTool() {
 
    }

    // User-Defined Constructor
    IronNugget() : nonTool(11, "IRON_NUGGET", "-", quantity) {
    }

    // Setter

    // Getter

};

#endif
