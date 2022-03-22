// sample main file, replace this with your own code
#include "main.hpp"

int main()
{
  map<pair<string, int>, string> recipe;
  readConfig(recipe);

  // map<string, Item> getItem;
  // Crafting craft = new Crafting();
  // for (auto x : recipe)
  // {
  //   cout << (x.first).first << " " << (x.first).second << endl;
  //   cout << x.second << endl;
  //   Crafting craft3 = craft;
  //   craft3 = craft2;
  //   craft3.symmetry();
  //   Item *res;
  //   if (craft.isCraftable(x.second))
  //     string item = x.first.first;
  //   int num = x.first.second;
  //   if (item == "DIAMOND")
  //   {
  //     res = new Diamond(num);
  //   }
  //   else if ()
  //     else if (craft3.isCraftable(x.second))
  //     {
  //       string item = craft3.getCraft(x.first, x.second);
  //     }
  //   break;

  //   cout << endl;
  // }
  // if craft
  //   .isCraftableTool() : // delete isinya di craft
  //                        craft.getcraftedtool();
  Inventory Itory = Inventory();
  Crafting Craft = Crafting();
  string configPath = "./config";
  string itemConfigPath = configPath + "/item.txt";

  // read item from config file
  ifstream itemConfigFile(itemConfigPath);

  for (string line; getline(itemConfigFile, line);)
  {
    // cout << line << endl;
    // do something
  }

  // // read recipes
  for (const auto &entry :
       filesystem::directory_iterator(configPath + "/recipe"))
  {
    cout << entry.path() << endl;
    // read from file and do something
  }

  // sample interaction
  string command;
  while (cin >> command)
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
      Itory.addToInventory(getItemFromString(itemName, itemQty));
    }
    else if (command == "DISCARD")
    {
      int InventoryID;
      int itemQty;
      cin >> InventoryID >> itemQty;
      if (Itory.getInventory(InventoryID)->isTool())
      {
        Itory.deleteFromInventory(to_string(InventoryID), 1);
      }
      else
      {
        if (Itory.getInventory(InventoryID)->getQuantity() > itemQty)
        {
          Itory.deleteFromInventory(to_string(InventoryID), itemQty);
        }
        else
        {
          cout << "Error!" << endl;
        }
      }
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
          if (Itory.getInventory(StringToInt(slotSrc))->getQuantity() >= slotQty)
          {
            for (int i = 0; i < slotQty; i++)
            {
              cin >> slotDest;
              Dest.push_back(slotDest);
            }
            Dest.push_back("0");
            for (int j = 0; j < slotQty; j++)
            {
              Craft.addToCrafting(Itory.getInventory(StringToInt(slotSrc)), StringToInt(Dest.front()));
              Dest.pop_front();
            }
            Itory.deleteFromInventory(to_string(StringToInt(slotSrc)), slotQty);
          }
          else
          {
            cout << "Tidak cukup!" << endl;
          }
        }
      }
      else
      {
        cin >> slotDest;
        if (slotDest.front() == 'I')
        {
          int x = slotSrc.back() - '0';
          int y = slotDest.back() - '0';
          Itory.addToInventory(to_string(x), Craft.getCrafting(y));
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
