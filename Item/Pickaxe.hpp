/* File: Pickaxe.hpp */
#ifndef __PICKAXE_HPP__
#define __PICKAXE_HPP__

#include "Tool.hpp"
// #include "ToolType.hpp"

/* Kelas Pickaxe */
template <class T>
class Pickaxe : public Tool {
private:
    /* Atribut */
    T pickaxeType;
public:
    // Default Constructor
    Pickaxe() : Tool() {
        T temp;
        setPickaxeType(temp);
    }

    // User-Defined Constructor
    Pickaxe(T pickaxeType) : Tool(13+pickaxeType.getId(), pickaxeType.getName()+"_PICKAXE", "-", 10) {
        setPickaxeType(pickaxeType);
    }

    // Setter pickaxeType
    void setPickaxeType(T pickaxeType) {
        this->pickaxeType = pickaxeType;
    }

    // Getter pickaxeType
    T getPickaxeType() const {
        return this->pickaxeType;
    }
};

#endif