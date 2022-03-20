/* File: IronIngot.hpp */
#ifndef __IRON_INGOT_HPP__
#define __IRON_INGOT_HPP__

#include "nonTool.hpp"

/* Kelas IronIngot */
class IronIngot : public nonTool {
private:
    /* Atribut */
    int quantity;
public:
    // Default Constructor
    IronIngot() : nonTool() {
 
    }

    // User-Defined Constructor
    IronIngot() : nonTool(10, "IRON_INGOT", "-", quantity) {
    }

    // Setter

    // Getter

};

#endif