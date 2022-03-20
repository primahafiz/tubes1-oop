// sample main file, replace this with your own code
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "Item/Diamond.hpp"
#include "Item/Item.hpp"

using namespace std;

map<string,int*>recipe;

// ini nanti pindahin aja ke main.hpp
void readConfig(){
  string configPath = "./config";
  for (const auto &entry :filesystem::directory_iterator(configPath + "/recipe"))
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

  Item *k=new Diamond();

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

  // // sample interaction
  // string command;
  // while (cin >> command)
  // {
  //   if (command == "SHOW")
  //   {
  //     for (int i = 0; i < 3; i++)
  //     {
  //       for (int j = 0; j < 6; j++)
  //       {
  //         if (j < 3)
  //         {
  //           cout << "      " << ends;
  //         }
  //         else
  //         {
  //           cout << "[C " << j - 3 + i * 3 << "] " << ends;
  //         }
  //       }
  //       cout << endl;
  //     }
  //     cout << endl;
  //     for (int i = 0; i < 3; i++)
  //     {
  //       for (int j = 0; j < 9; j++)
  //       {
  //         if (j + i * 9 > 9)
  //         {
  //           cout << "[I" << j + i * 9 << "] " << ends;
  //         }
  //         else
  //         {
  //           cout << "[I " << j + i * 9 << "] " << ends;
  //         }
  //       }
  //       cout << endl;
  //     }
  //   }
  //   else if (command == "GIVE")
  //   {
  //     string itemName;
  //     int itemQty;
  //     cin >> itemName >> itemQty;
  //     cout << "TODO" << endl;
  //   }
  //   else if (command == "DISCARD")
  //   {
  //   }
  //   else if (command == "MOVE")
  //   {
  //     string slotSrc;
  //     int slotQty;
  //     string slotDest;
  //     // need to handle multiple destinations
  //     cin >> slotSrc >> slotQty >> slotDest;
  //     cout << "TODO" << endl;
  //   }
  //   else if (command == "USE")
  //   {
  //   }
  //   else if (command == "CRAFT")
  //   {
  //     cout << "TODO" << endl;
  //   }
  //   else if (command == "EXPORT")
  //   {
  //     string outputPath;
  //     cin >> outputPath;
  //     ofstream outputFile(outputPath);

  //     // hardcode for first test case
  //     outputFile << "21:10" << endl;
  //     outputFile << "6:1" << endl;
  //     for (int i = 2; i < 27; i++)
  //     {
  //       outputFile << "0:0" << endl;
  //     }

  //     cout << "Exported" << endl;
  //   }
  //   else if (command == "EXIT")
  //   {
  //     break;
  //   }
  //   else
  //   {
  //     // todo
  //     cout << "Invalid command" << endl;
  //   }
  // }
  // return 0;
}
