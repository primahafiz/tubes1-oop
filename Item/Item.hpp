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
    string type;    // jenis item
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
    virtual bool isTool()=0;

    // Setter Quantity
    virtual void setQuantity(int quantity);

    // Getter Quantity
    virtual int getQuantity() const;
    
    // modifyQuantity: menambahkan quantity item non tool sebanyak amount
    // Variabel amount dapat bernilai positif/negatif
    virtual void modifyQuantity(int amount);

    // Setter durability
    virtual void setDurability(int durability);

    // Getter durability
    virtual int getDurability() const;
    
    // modifyDurability: menambahkan durability tool sebanyak changes
    // Variabel changes dapat bernilai positif/negatif
    virtual void modifyDurability(int changes);
};

#endif