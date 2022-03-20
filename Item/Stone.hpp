/* File: Stone.hpp */
#ifndef __STONE_HPP__
#define __STONE_HPP__

#include "nonTool.hpp"
#include "nonToolType.hpp"

/* Kelas Stone */
template <class T>
class Stone : public nonTool {
private:
    /* Atribut */
    T stoneType;
public:
    // Default Constructor
    Stone() : nonTool() {
        T temp;
        setStoneType(temp);
    }

    // User-Defined Constructor
    Stone(T stoneType, int quantity) : nonTool(8+stoneType.getId(), stoneType.getName(), "STONE", quantity) {
        setStoneType(stoneType);
    }

    // Setter stoneType
    void setStoneType(T stoneType) {
        this->stoneType = stoneType;
    }

    // Getter stoneType
    T getStoneType() const {
        return this->stoneType;
    }
};

#endif
