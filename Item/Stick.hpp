/* File: Stick.hpp */
#ifndef __STICK_HPP__
#define __STICK_HPP__

#include "nonTool.hpp"

/* Kelas Stick */
class Stick : public nonTool {
private:
    /* Atribut */
    int quantity;
public:
    // Default Constructor
    Stick() : nonTool() {
 
    }

    // User-Defined Constructor
    Stick() : nonTool(4, "STICK", "-", quantity) {
    }

    // Setter

    // Getter

};

#endif