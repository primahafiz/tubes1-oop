/* File: Sword.hpp */
#ifndef __SWORD_HPP__
#define __SWORD_HPP__

#include "Tool.hpp"
#include "ToolType.hpp"
#include <map>
#include <tuple>

extern map <string, tuple<int, string, string>> itemConfig;

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
    Sword(T swordType) : Tool(get<0>(itemConfig.find(swordType.getName()+"_SWORD")->second), swordType.getName()+"_SWORD", get<1>(itemConfig.find(swordType.getName()+"_SWORD")->second), 10)
    {
        setSwordType(swordType);
    }

    // Setter swordType
    void setSwordType(T swordType)
    {
        this->swordType = swordType;
    }

    // Getter swordType
    T getSwordType() const 
    {
        return this->swordType;
    }
};

#endif