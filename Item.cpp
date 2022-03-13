/* File: Item.cpp */
#include "Item.hpp"

// Default Constructor
Item::Item() {
    setID(0);
    setName("Item");
    setType("-");
}

// User-Defined Constructor
Item::Item(int id, string name, string type) {
    setID(id);
    setName(name);
    setType(type);
}

// Setter id
void Item::setID(int id) {
    this->id = id;
}

// Getter id
int Item::getID() const {
    return this->id;
}

// Setter name
void Item::setName(string name) {
    this->name = name;
}

// Getter name
string Item::getName() const {
    return this->name;
}

// Setter type
void Item::setType(string type) {
    this->type = type;
}

// Getter type
string Item::getType() const {
    return this->type;
}