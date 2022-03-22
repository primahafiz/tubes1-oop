/* File: Sword.hpp */
#ifndef __SWORD_HPP__
#define __SWORD_HPP__

#include "Tool.hpp"
#include "ToolType.hpp"

/* Kelas Sword */
template <class T>
class Sword : public Tool {
private:
    /* Atribut */
    T swordType;
public:
    // Default Constructor
    Sword() : Tool() {
        T temp;
        setSwordType(temp);
    }

    // User-Defined Constructor
    Sword(T swordType) : Tool(21+swordType.getId(), swordType.getName()+"_SWORD", "-", 10) {
        setSwordType(swordType);
    }

    // Setter swordType
    void setSwordType(T swordType) {
        this->swordType = swordType;
    }

    // Getter swordType
    T getSwordType() const {
        return this->swordType;
    }
};

#endif