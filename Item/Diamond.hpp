/* File: Diamond.hpp */
#ifndef __DIAMOND_HPP__
#define __DIAMOND_HPP__

#include "nonTool.hpp"

/* Kelas Diamond */
class Diamond : public nonTool {
private:
    /* Atribut */
public:
    // Default Constructor
    Diamond() : nonTool() {
 
    }

    // User-Defined Constructor
    Diamond(int quantity) : nonTool(12, "DIAMOND", "-", quantity) {

    }

    // Setter

    // Getter

};

#endif