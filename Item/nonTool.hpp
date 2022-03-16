/* File: nonTool.hpp */
#ifndef __NON_TOOL_HPP__
#define __NON_TOOL_HPP__

#include "Item.hpp"

/* Kelas NonTool */
class nonTool : public Item {
private:
    /* Atribut */
    int quantity;     // quantity item
public:
    // Default Constructor
    nonTool();

    // User-Defined Construtor
    nonTool(int id, string name, string type, int quantity);

    // Setter Quantity
    void setQuantity(int quantity);

    // Getter Quantity
    int getQuantity() const;
    
    // modifyQuantity: menambahkan quantity item non tool sebanyak amount
    // Variabel amount dapat bernilai positif/negatif
    void modifyQuantity(int amount);

    // isTool: mengecek kategori item (TOOL/NONTOOL)
    // Mengembalikan true jika item masuk kategori TOOL
    bool isTool();
};

#endif