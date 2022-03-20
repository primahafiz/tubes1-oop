/* File: Plank.hpp */
#ifndef __PLANK_HPP__
#define __PLANK_HPP__

#include "nonTool.hpp"
#include "nonToolType.hpp"

/* Kelas Plank */
template <class T>
class Plank : public nonTool {
private:
    /* Atribut */
    T plankType;
public:
    // Default Constructor
    Plank() : nonTool() {
        T temp;
        setPlankType(temp);
    }

    // User-Defined Constructor
    Plank(T plankType, int quantity) : nonTool(4+plankType.getId(), plankType.getName()+"_PLANK", "PLANK", quantity) {
        setPlankType(plankType);
    }

    // Setter plankType
    void setPlankType(T plankType) {
        this->plankType = plankType;
    }

    // Getter plankType
    T getPlankType() const {
        return this->plankType;
    }
};

#endif
