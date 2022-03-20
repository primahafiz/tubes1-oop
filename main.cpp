// sample main file, replace this with your own code
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include "headd.hpp"

using namespace std;

// ini nanti pindahin aja ke main.hpp
void readConfig(map<pair<string,int>,string> &recipe)
{
  string configPath = "./config";
  for (const auto &entry : filesystem::directory_iterator(configPath + "/recipe"))
  {

    ifstream checkLine(entry.path());

    int numLine=0;
    for(string line;getline(checkLine,line);){
      numLine++;
    }

    ifstream recipeConfigFile(entry.path());

    string ret="";
    string infoItem="";
    int num=0;

    int iter = 0;

    for (string line; getline(recipeConfigFile, line);)
    {
        iter++;

        if(iter==1)continue;

        int n=line.size();
        if(iter!=numLine){
          for(int i=0;i<n;i++){
              if(line[i]==' ')continue;
              ret+=line[i];
          }
        }else{
          for(int i=0;i<n;i++){
            if(line[i]==' ')break;
            infoItem+=line[i];
          }
          int mul=1;
          for(int i=n-1;i>=0;i--){
            if(line[i]==' ')break;
            num+=(line[i]-'0')*mul;
            mul*=10;
          }
        }
    }
    int nRes=ret.size();
    for(int i=nRes-1;i>=0;i--){
      if(ret[i]!='-'){
        ret=ret.substr(0,i+1);
        break;
      }
    }
    recipe[{infoItem,num}]=ret;
  }
}

int main()
{
  map<pair<string,int>,string> recipe;
  Inventory Itory = Inventory();
  Crafting Craft = Crafting();

  readConfig(recipe);

  for(auto x:recipe){
    cout<<(x.first).first<<" "<<(x.first).second<<endl;
    cout<<x.second<<endl;
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
      temp->modifyQuantity(-itemQty);
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
      temp->modifyQuantity(-1);
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
