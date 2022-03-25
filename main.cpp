/* MAIN PROGRAM */
#include "head.hpp"

// Global Variables
map<string, tuple<int, string, string>> itemConfig;

int main()
{
  // Variables
  map<pair<string, int>, pair<string,int>> recipe;
  readConfig(recipe, itemConfig);
  Inventory Itory = Inventory();
  Crafting Craft = Crafting();

  // Commands
  string command;
  cout << ">> ";
  while (cin >> command)
  {
    try
    {
      if (command == "SHOW")
      {
        Craft.printCrafting();
        Itory.printInventory();
      }

      else if (command == "GIVE")
      {
        string itemName;
        int itemQty;
        cin >> itemName >> itemQty;
        if(!getItemFromString(itemName, itemQty)->isTool()){
          Itory<<getItemFromString(itemName, itemQty);
        }else{
          if(Itory.getAvailableSlot(getItemFromString(itemName,1))<itemQty){
            throw new InventoryFullException();
          }else{
            for(int i=0;i<itemQty;i++){
              Item *a=getItemFromString(itemName,1);
              Itory<<a;
            }
          }
        }
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
            else if(slotDest.front() == 'C')
            {
              if(Itory.getInventory(StringToInt(slotSrc))==NULL){
                throw new ItemNullException();
              }
              Craft.addToCrafting(Itory.getInventory(StringToInt(slotSrc)), StringToInt(slotDest));
              Itory.deleteFromInventory(slotSrc, 1);
            }else
            {
              throw new IDException();
            }
          }
          else
          {
            if(Itory.getInventory(StringToInt(slotSrc))!=NULL)
            {
              if(!Itory.getInventory(StringToInt(slotSrc))->isTool())
              {
                  if (Itory.getInventory(StringToInt(slotSrc))->getQuantity() >= slotQty)
                  {
                    for (int i = 0; i < slotQty; i++)
                    {
                      cin >> slotDest;
                      if(slotDest.front()!='C'){
                        throw new IDException();
                      }
                      int ID=StringToInt(slotDest);
                      Dest.push_back(slotDest);
                    }
                    for (int j = 0; j < slotQty; j++)
                    {
                      Craft.addToCrafting(Itory.getInventory(StringToInt(slotSrc)), StringToInt(Dest.front()));
                      Dest.pop_front();
                    }
                    Itory.deleteFromInventory(slotSrc, slotQty);
                  }
                  else
                  {
                    throw new DeleteInventoryException();
                  }
                }
                else
                {
                  throw new ItemNotNonToolException();
                }
            }
            else
            {
              throw new ItemNullException();
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
            throw new IDException();
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
            throw new ItemNotToolException();
          }
        }
        else
        {
          throw new ItemNullException();
        }
      }

      else if (command == "CRAFT")
      // Dicek jika bisa craft tool tanpa recipe
      // jika tidak, cek resep
      //  looping respnya (per satu file)
      //  Dalam looping, dicek bisa atau ga
      {
        if (Craft.isToolCraftable())
        {
          Item *x = Craft.getToolCraftable();
          Itory<<x;
        }
        else
        {
          int countCraftable = 0;
          for (auto x : recipe)
          {
            if (Craft.isCraftable(x.second.first,x.second.second))
            {
              countCraftable++;
            }
          }        
          if (countCraftable == 0)
          {
            cout << "Not craftable" << endl;
          }
          else if (countCraftable == 1)
          {
            for (auto x : recipe)
            {
              if (Craft.isCraftable(x.second.first,x.second.second))
              {
                Item *item = getItemFromString((x.first).first, (x.first).second);
                Itory<<item;
                Craft.clearCrafting();
                break;
              }
            }          
          }
          else
          {
            for (auto x : recipe)
            {
              cout<<x.first.first<<endl;
              if (Craft.isExactCraftable(x.second.first))
              {
                Item *item = getItemFromString((x.first).first, (x.first).second);
                Itory<<item;
                Craft.clearCrafting();
                break;
              }
            }   
          }
        }
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
    catch(BaseException *e)
    {
      e->printMessage();
    }
    cout << ">> ";
  }
  return 0;
}
