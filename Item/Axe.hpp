/* File: Axe.hpp */
#ifndef __AXE_HPP__
#define __AXE_HPP__

#include "Tool.hpp"
#include "ToolType.hpp"

/* Kelas Axe */
template <class T>
class Axe : public Tool {
private:
    /* Atribut */
    T axeType;
public:
    // Default Constructor
    Axe() : Tool() {
        T temp;
        setAxeType(temp);
    }

    // User-Defined Constructor
    Axe(T axeType) : Tool(17+axeType.getId(), axeType.getName()+"_AXE", "-", 10) {
        setAxeType(axeType);
    }

    // Setter axeType
    void setAxeType(T axeType) {
        this->axeType = axeType;
    }

    // Getter axeType
    T getAxeType() const {
        return this->axeType;
    }
};

#endif