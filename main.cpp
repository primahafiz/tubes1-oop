// sample main file, replace this with your own code
#include "head.hpp"

map<string, tuple<int, string, string>> itemConfig;

int main()
{
  map<pair<string, int>, string> recipe;
  readConfig(recipe, itemConfig);
  Inventory Itory = Inventory();
  Crafting Craft = Crafting();

  for (auto x : recipe){
    cout<<"resep saat ini"<<x.second<<"\n";
    if (x.second == "DIAMONDDIAMOND-DIAMONDSTICK--STICK"){
      cout << "ketemu" << endl;
    }
  }

  // sample interaction
  string command;
  while (cin >> command)
  {
    if (command == "SHOW")
    {
      Craft.printCrafting();
      Itory.printInventory();
      cout << endl;
    }
    else if (command == "GIVE")
    {
      string itemName;
      int itemQty;
      cin >> itemName >> itemQty;
      Itory.addToInventory(getItemFromString(itemName, itemQty));
    }
    else if (command == "DISCARD")
    {
      string InventoryID;
      int itemQty;
      cin >> InventoryID >> itemQty;
      Itory.deleteFromInventory(InventoryID, itemQty);
    }
    else if (command == "MOVE")
    {

      string slotSrc;
      int slotQty;
      string slotDest;
      list<string> Dest;
      cin >> slotSrc >> slotQty;
      if (slotSrc.front() == 'I')
      {
        if (slotQty == 1)
        {
          cin >> slotDest;
          if (slotDest.front() == 'I')
          {
            Itory.combineTwoItem(slotSrc, slotDest);
          }
          else
          {
            Craft.addToCrafting(Itory.getInventory(StringToInt(slotSrc)), StringToInt(slotDest));
            Itory.deleteFromInventory(slotSrc, 1);
          }
        }
        else
        {
          if(Itory.getInventory(StringToInt(slotSrc))!=NULL){
            if(!Itory.getInventory(StringToInt(slotSrc))->isTool()){
                if (Itory.getInventory(StringToInt(slotSrc))->getQuantity() >= slotQty)
                {
                  for (int i = 0; i < slotQty; i++)
                  {
                    cin >> slotDest;
                    Dest.push_back(slotDest);
                  }
                  for (int j = 0; j < slotQty; j++)
                  {
                    Craft.addToCrafting(Itory.getInventory(StringToInt(slotSrc)), StringToInt(Dest.front()));
                    Dest.pop_front();
                  }
                  Itory.deleteFromInventory(slotSrc, slotQty);
                }else{
                  cout<<"Item tidak cukup"<<endl;
                }
              }else{
                cout<<"Item bukan Non Tool"<<endl;
              }
          }
          else
          {
            cout << "Inventory kosong" << endl;
          }
        }
      }
      else
      {
        cin >> slotDest;
        if (slotDest.front() == 'I')
        {
          int y = StringToInt(slotSrc);
          Itory.addToInventory(slotDest, Craft.getCrafting(y));
          Craft.deleteCrafting(y);
        }
        else
        {
          cout << "Input MOVE Salah!" << endl;
        }
      }
    }
    else if (command == "USE")
    {
      string InventoryID;
      cin >> InventoryID;
      if (Itory.getInventory(StringToInt(InventoryID)) != NULL)
      {
        if (Itory.getInventory(StringToInt(InventoryID))->isTool())
        {
          if (Itory.getInventory(StringToInt(InventoryID))->getDurability() > 1)
          {
            Itory.getInventory(StringToInt(InventoryID))->modifyDurability(-1);
          }
          else
          {
            Itory.deleteFromInventory(InventoryID, 1);
          }
        }
        else
        {
          cout << "Inventory slot bukan berisi Tool!" << endl;
        }
      }
      else
      {
        cout << "Tidak ada Item!" << endl;
      }
    }
    else if (command == "CRAFT")
    {
      if (Craft.isToolCraftable())
      {
        Item *x = Craft.getToolCraftable();
        Itory.addToInventory(x);
      }
      else
      {
        /*
        for (auto x : recipe)
        {
          // cout << "resep saat ini" << x.second <<" "<<Craft.getStringCrafting()<< endl;
          if (Craft.isCraftable(x.second))
          {
            Item *item = getItemFromString((x.first).first, (x.first).second);
            Itory.addToInventory(item);
            Craft.clearCrafting();
            break;
          }
        }
        */
        int countCraftable = 0;
        for (auto x : recipe)
        {
          // cout << "resep saat ini" << x.second <<" "<<Craft.getStringCrafting()<< endl;
          if (Craft.isCraftable(x.second))
          {
            countCraftable++;
          }
        }        

        if (countCraftable == 0){
          cout << "Not craftable" << endl;
        } else if (countCraftable == 1){

          for (auto x : recipe)
          {
            if (Craft.isCraftable(x.second))
            {
              Item *item = getItemFromString((x.first).first, (x.first).second);
              Itory.addToInventory(item);
              Craft.clearCrafting();
              break;
            }
          }          

        } else {

          for (auto x : recipe)
          {
            // cout << "resep saat ini" << x.second <<" "<<Craft.getStringCrafting()<< endl;
            if (Craft.isExactCraftable(x.second))
            {
              Item *item = getItemFromString((x.first).first, (x.first).second);
              Itory.addToInventory(item);
              Craft.clearCrafting();
              break;
            }
          }   
          
        }
      }
      // Dicek jika bisa craft tool tanpa recipe
      // jika tidak, cek resep
      //  looping respnya (per satu file)
      //  Dalam looping, dicek bisa atau ga
    }
    else if (command == "EXPORT")
    {
      string outputPath;
      cin >> outputPath;
      Itory.exportInventory(outputPath);
      cout << "Exported" << endl;
    }
    else if (command == "EXIT")
    {
      break;
    }
    else
    {
      cout << "Invalid command" << endl;
    }
  }
  return 0;
}
