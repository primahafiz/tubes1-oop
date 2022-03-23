/* File: Pickaxe.hpp */
#ifndef __PICKAXE_HPP__
#define __PICKAXE_HPP__

#include "Tool.hpp"
#include "ToolType.hpp"
#include <map>
#include <tuple>

extern map <string, tuple<int, string, string>> itemConfig;

/* Kelas Pickaxe */
template <class T>
class Pickaxe : public Tool {
private:
    /* Atribut */
    T pickaxeType;
public:
    // Default Constructor
    Pickaxe() : Tool()
    {
        T temp;
        setPickaxeType(temp);
    }

    // User-Defined Constructor
    Pickaxe(T pickaxeType) : Tool(get<0>(itemConfig.find(pickaxeType.getName()+"_PICKAXE")->second), pickaxeType.getName()+"_PICKAXE", get<1>(itemConfig.find(pickaxeType.getName()+"_PICKAXE")->second), 10)
    {
        setPickaxeType(pickaxeType);
    }

    // Setter pickaxeType
    void setPickaxeType(T pickaxeType)
    {
        this->pickaxeType = pickaxeType;
    }

    // Getter pickaxeType
    T getPickaxeType() const
    {
        return this->pickaxeType;
    }
};

#endif