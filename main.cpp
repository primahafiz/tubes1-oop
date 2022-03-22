// sample main file, replace this with your own code
#include "main.hpp"

int main()
{
  // map<pair<string, int>, string> recipe;
  // readConfig(recipe);

  // map<string, Item> getItem;
  // Crafting craft=new Crafting();
  // for(auto x:recipe){
  //   cout<<(x.first).first<<" "<<(x.first).second<<endl;
  //   cout<<x.second<<endl;
  // Crafting craft3 = craft;
  // craft3 = craft2;
  //   craft3.symmetry();
  //   Item *res;
  //   if (craft.isCraftable(x.second))
  //     string item = x.first.first;
  //     int num=x.first.second;
  //     if(item=="DIAMOND"){
  //       res=new Diamond(num);
  //     }else if()
  //   else if(craft3.isCraftable(x.second)){
  //     string item = craft3.getCraft(x.first,x.second);
  //   }
  //     break;

  //   cout<<endl;
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
    // cout << entry.path() << endl;
    // read from file and do something
  }

  // // sample interaction
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
        Itory.deleteFromInventory(to_string(InventoryID), itemQty);
      }
    }
    else if (command == "MOVE")
    {

      // string slotSrc;
      // int slotQty;
      // string slotDest;
      // need to handle multiple destinations
      // cin >> slotSrc >> slotQty >> slotDest;
      // cout << "TODO" << endl;
      string s;
      getline(cin, s);

      string ret = "";

      vector<string> v;

      for (int i = 0; i < v.size(); i++)
      {
        if (s[i] == ' ')
        {
          v.push_back(ret);
          ret = "";
        }
        else
        {
          ret += s[i];
        }
      }
      v.push_back(ret);
      for (string sx : v)
      {
        cout << sx << endl;
      }
    }
    else if (command == "USE")
    {
      int ToolID;
      cin >> ToolID;
      // cari item dari id tertentu
      for (int i = 0; i < 27; i++)
      {
        if (Itory.getInventory(i)->isTool())
        {
          if (Itory.getInventory(i)->getID() == ToolID)
          {
            Itory.getInventory(i)->modifyQuantity(-1);
          }
        }
      }
    }
    // else if (command == "CRAFT")
    // {
    //   cout << "TODO" << endl;
    // }
    // else if (command == "EXPORT")
    // {
    //   string outputPath;
    //   cin >> outputPath;
    //   ofstream outputFile(outputPath);

    //   // hardcode for first test case
    //   outputFile << "21:10" << endl;
    //   outputFile << "6:1" << endl;
    //   for (int i = 2; i < 27; i++)
    //   {
    //     outputFile << "0:0" << endl;
    //   }

    //   cout << "Exported" << endl;
    // }
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
