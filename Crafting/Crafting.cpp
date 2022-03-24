#include"Crafting.hpp"
#include<string>
#include<vector>

Crafting::Crafting(){
    this->crafting = new SlotCrafting[9];    
    for (int i = 0; i < 9; i++){
        crafting[i] = SlotCrafting();
    }
}

Crafting::~Crafting(){
    delete[] this->crafting;
}

// add sebuah Item pada slot crafting ke i
void Crafting::addToCrafting(Item *a, int i){
    if (i >= 0 && i <= 8){
        if (this->crafting[i].isSlotCraftingEmpty()){
            crafting[i].addSlotCrafting(getItemFromString(a->getName(),1));
        } else {
            throw CraftingFullException();
        }        
    } else {
        throw CraftingIndexException();
    }
}
 
// delete sebuah Item pada slot crafting ke i
void Crafting::deleteCrafting(int i){
    if (i >= 0 && i <= 8){
        if (!this->crafting[i].isSlotCraftingEmpty()){
            crafting[i].dropSlotCrafting();
        } else {
            throw CraftingNullException();
        }
    } else {
        throw CraftingIndexException();
    }
}

// mengambil item pada slot crafting ke i
Item* Crafting::getCrafting(int i){
    return crafting[i].getSlotCraftingItem();
}

// clear crafting
void Crafting::clearCrafting(){
    for (int i = 0; i < 9; i++){
        if(this->crafting[i].isSlotCraftingEmpty())continue;
        deleteCrafting(i);
    }
}

// cek apakah slot crafting ke i kosong
bool Crafting::isCraftingEmpty(int i){
    return crafting[i].isSlotCraftingEmpty();
}

// swap position item i and j, untuk symmetry
void Crafting::swap(int i, int j){
    if(this->crafting[i].isSlotCraftingEmpty() || this->crafting[j].isSlotCraftingEmpty()){
        if(this->crafting[i].isSlotCraftingEmpty() && this->crafting[j].isSlotCraftingEmpty()){
            //
        }else if(this->crafting[i].isSlotCraftingEmpty()){
            addToCrafting(getCrafting(j),i);
            deleteCrafting(j);
        }else{
            addToCrafting(getCrafting(i),j);
            deleteCrafting(i);
        }
    }else{
        Item *a = getCrafting(j);
        deleteCrafting(j);
        addToCrafting(getCrafting(i),j);
        deleteCrafting(i);
        addToCrafting(a,i);
    }
}

// membuat resep crafting yang direfleksi terhadap sumbu  y
void Crafting::symmetry(){
    swap(0, 2);
    swap(3, 5);
    swap(6, 8);
}

string Crafting::getStringCrafting(){
    string crafting = "";

    for (int i = 0; i < 9; i++){
        if (isCraftingEmpty(i)){
            crafting += "-";
        } else {
            if(getCrafting(i)->getType() == "-"){
                crafting += getCrafting(i)->getName();                
            } else {
                if (getCrafting(i)->getType() == "LOG"){
                    crafting += getCrafting(i)->getName();                    
                } else {
                    crafting += getCrafting(i)->getType();                      
                }               
            }
        }
    }

    return crafting;
}

// helper function
bool Crafting::Craftable (string X){
    string crafting = getStringCrafting();
    size_t found = crafting.find(X);
    
    if (found != string::npos){
        return true;
    } else {
        return false;
    }

}

// helper function
bool Crafting::CraftableSymmetry (string X){
    symmetry();
    string crafting = getStringCrafting();
    symmetry();

   
    size_t found = crafting.find(X);
    if (found != string::npos){
        return true;
    } else {
        return false;
    }
}

// mengecek apakah craftable
bool Crafting::isCraftable(string X){
    bool craftable = false;

    if (Craftable(X) || CraftableSymmetry(X)){
        craftable = true;
    }
    return craftable;
}

bool Crafting::ExactCraftable(string X){
    string crafting = getStringCrafting();
    crafting = cutString(crafting);

    if (X == crafting){
        return true;
    } else {
        return false;
    }
}

// helper function 
bool Crafting::ExactCraftableSymmetry (string X){
    symmetry();
    string crafting = getStringCrafting();
    crafting = cutString(crafting);
    symmetry();

    if (X == crafting){
        return true;
    } else {
        return false;
    }
}

// mengecek apakah craftable
bool Crafting::isExactCraftable(string X){
    bool craftable = false;


    if (ExactCraftable(X) || ExactCraftableSymmetry(X)){
        craftable = true;
    }
    return craftable;    
}

// return total durability dari item yang ada di crafting
int Crafting::totalDurability(){
    int total = 0;
    for (int i = 0; i < 9; i++){
        if(!isCraftingEmpty(i) && getCrafting(i)->isTool()){
            total += getCrafting(i)->getDurability();
        }
    }
    return total;
}

// mengecek apakah slot selain indeks a dan b kosong
bool Crafting::isOtherThanEmpty(int a, int b){
    bool empty = true;
    for (int i = 0; i < 9; i++){
        if (i != a && i != b){
            if (!isCraftingEmpty(i)){
                empty = false;
            }
        }
    }
    return empty;
}

// mengecek apakah kedua item tool craftable
bool Crafting::isToolCraftable(){
    int countTool = 0;
    bool craftable = false;
    vector<int> idx;

    for (int i = 0; i < 9; i++){
        if (!isCraftingEmpty(i)){
            if (getCrafting(i)->isTool()){
                countTool += 1;
                cout << i << endl;
                idx.push_back(i);
            }            
        }
    }

    if (countTool == 2){
        if (getCrafting(idx[0])->getType() == getCrafting(idx[1])->getType()){
            if (isOtherThanEmpty(idx[0], idx[1])){               
                craftable = true;
            }
        }
    } 

    return craftable;
}

// crafting kedua item tool
Item* Crafting::getToolCraftable(){
    int countTool = 0;
    vector<int> idx;

    for (int i = 0; i < 9; i++){
        if (!isCraftingEmpty(i)){
            if (getCrafting(i)->isTool()){
                countTool += 1;
                cout << i << endl;
                idx.push_back(i);
            }            
        }
    }
        
    int id = getCrafting(idx[0])->getID();
    string name = getCrafting(idx[0])->getName();
    string type = getCrafting(idx[0])->getType();
    int oriDurability = (getCrafting(idx[0])->getDurability() + getCrafting(idx[0])->getDurability());
    int durability = min(10, oriDurability);

    Item* tool = new Tool(id, name, type, durability);

    clearCrafting();
    return tool;
}

// print slot crafting
void Crafting::printCrafting(){
    for (int i = 0; i < 9; i++){
        if (i == 0 || i == 3 || i == 6){
            cout << string(30, ' ');
        }
        crafting[i].printSlotCrafting();
        if (i == 2 || i == 5 || i == 8){
            cout << "\n";
        }
    }
}
