/* File: Item.hpp */
#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <string>
using namespace std;

class Item {
private:
    /* Atribut */
    int id;         // id item
    string name;    // nama item
    string type;   // jenis item
public:
    // Default Constructor
    Item();

    // User-Defined Constructor
    Item(int id, string name, string type);
    
    // Setter id
    void setID(int id);

    // Getter id
    int getID() const;
    
    // Setter name
    void setName(string name);
    
    // Getter name
    string getName() const;
    
    // Setter type
    void setType(string type);

    // Getter type
    string getType() const;
    
    // isTool: mengecek kategori item (TOOL/NONTOOL)
    // Mengembalikan true jika item masuk kategori TOOL
    virtual bool isTool();
};

#endif