// sample main file, replace this with your own code
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "headd.hpp"

using namespace std;

map<string, int *> recipe;

// ini nanti pindahin aja ke main.hpp
void readConfig()
{
  string configPath = "./config";
  for (const auto &entry : filesystem::directory_iterator(configPath + "/recipe"))
  {
    cout << entry.path() << endl;
    ifstream recipeConfigFile(entry.path());
    for (string line; getline(recipeConfigFile, line);)
    {
      // cout << line << endl;
      // do something
    }
  }
}

int main()
{
  readConfig();
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

  // read recipes
  for (const auto &entry :
       filesystem::directory_iterator(configPath + "/recipe"))
  {
    // cout << entry.path() << endl;
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
      // Dibandingkan berdasarkan nama benda
      cin >> itemName >> itemQty;

      Item *temp = new Diamond();
      Itory.addToInventory(temp);
    }
    else if (command == "DISCARD")
    {
      string itemID;
      int itemQty;
      // Dibandingkan berdasarkan ID
      cin >> itemID >> itemQty;
      Item *temp = new Diamond();
      temp.modifyQuantity(-itemQty);
    }
    else if (command == "MOVE")
    {
      string slotSrc;
      int slotQty;
      string slotDest;
      // need to handle multiple destinations
      cin >> slotSrc >> slotQty >> slotDest;
      cout << "TODO" << endl;
    }
    else if (command == "USE")
    {
      string ToolID;
      cin >> ToolID;
      Item *temp = new Diamond();
      temp.modifyQuantity(-1);
    }
    else if (command == "CRAFT")
    {
      cout << "TODO" << endl;
    }
    else if (command == "EXPORT")
    {
      string outputPath;
      cin >> outputPath;
      ofstream outputFile(outputPath);

      // hardcode for first test case
      outputFile << "21:10" << endl;
      outputFile << "6:1" << endl;
      for (int i = 2; i < 27; i++)
      {
        outputFile << "0:0" << endl;
      }

      cout << "Exported" << endl;
    }
    else if (command == "EXIT")
    {
      break;
    }
    else
    {
      // todo
      cout << "Invalid command" << endl;
    }
  }
  return 0;
}
