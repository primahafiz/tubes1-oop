/* File: Plank.hpp */
#ifndef __PLANK_HPP__
#define __PLANK_HPP__

#include "nonTool.hpp"
#include "nonToolType.hpp"
#include <map>
#include <tuple>

extern map <string, tuple<int, string, string>> itemConfig;

/* Kelas Plank */
template <class T>
class Plank : public nonTool {
private:
    /* Atribut */
    T plankType;
public:
    // Default Constructor
    Plank() : nonTool()
    {
        T temp;
        setPlankType(temp);
    }

    // User-Defined Constructor
    Plank(T plankType, int quantity) : nonTool(get<0>(itemConfig.find(plankType.getName()+"_PLANK")->second), plankType.getName()+"_PLANK", get<1>(itemConfig.find(plankType.getName()+"_PLANK")->second), quantity)
    {
        setPlankType(plankType);
    }

    // Setter plankType
    void setPlankType(T plankType)
    {
        this->plankType = plankType;
    }

    // Getter plankType
    T getPlankType() const
    {
        return this->plankType;
    }
};

#endif
