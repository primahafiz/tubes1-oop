/* File: main.hpp */
#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <list>
#include "head.hpp"
using namespace std;

void readConfig(map<pair<string, int>, string> &recipe)
{
    string configPath = "./config";
    for (const auto &entry : filesystem::directory_iterator(configPath + "/recipe"))
    {

        ifstream checkLine(entry.path());

        int numLine = 0;
        for (string line; getline(checkLine, line);)
        {
            numLine++;
        }

        ifstream recipeConfigFile(entry.path());

        string ret = "";
        string infoItem = "";
        int num = 0;

        int iter = 0;

        for (string line; getline(recipeConfigFile, line);)
        {
            iter++;

            if (iter == 1)
                continue;

            int n = line.size();
            if (iter != numLine)
            {
                for (int i = 0; i < n; i++)
                {
                    if (line[i] == ' ')
                        continue;
                    ret += line[i];
                }
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    if (line[i] == ' ')
                        break;
                    infoItem += line[i];
                }
                int mul = 1;
                for (int i = n - 1; i >= 0; i--)
                {
                    if (line[i] == ' ')
                        break;
                    num += (line[i] - '0') * mul;
                    mul *= 10;
                }
            }
        }
        int nRes = ret.size();
        for (int i = nRes - 1; i >= 0; i--)
        {
            if (ret[i] != '-')
            {
                ret = ret.substr(0, i + 1);
                break;
            }
        }
        recipe[{infoItem, num}] = ret;
    }
}

Item *getItemFromString(string s, int num)
{
    if (s == "DIAMOND")
    {
        return new Diamond(num);
    }
    else if (s == "IRON_INGOT")
    {
        return new IronIngot(num);
    }
    else if (s == "IRON_NUGGET")
    {
        return new IronNugget(num);
    }
    else if (s == "OAK_LOG")
    {
        Oak OAK;
        return new Log(OAK, num);
    }
    else if (s == "SPRUCE_LOG")
    {
        Spruce SPRUCE;
        return new Log(SPRUCE, num);
    }
    else if (s == "BIRCH_LOG")
    {
        Birch BIRCH;
        return new Log(BIRCH, num);
    }
    else if (s == "OAK_PLANK")
    {
        Oak OAK;
        return new Plank(OAK, num);
    }
    else if (s == "SPRUCE_PLANK")
    {
        Spruce SPRUCE;
        return new Plank(SPRUCE, num);
    }
    else if (s == "BIRCH_PLANK")
    {
        Birch BIRCH;
        return new Plank(BIRCH, num);
    }
    else if (s == "STICK")
    {
        return new Stick(num);
    }
    else if (s == "COBBLESTONE")
    {
        Cobblestone COBBLESTONE;
        return new Stone(COBBLESTONE, num);
    }
    else if (s == "BLACKSTONE")
    {
        Blackstone BLACKSTONE;
        return new Stone(BLACKSTONE, num);
    }
    else if (s == "WOODEN_AXE")
    {
        WoodenType WOODEN;
        return new Axe(WOODEN);
    }
    else if (s == "STONE_AXE")
    {
        StoneType STONE;
        return new Axe(STONE);
    }
    else if (s == "IRON_AXE")
    {
        IronType IRON;
        return new Axe(IRON);
    }
    else if (s == "DIAMOND_AXE")
    {
        DiamondType DIAMOND;
        return new Axe(DIAMOND);
    }
    else if (s == "WOODEN_SWORD")
    {
        WoodenType WOODEN;
        return new Sword(WOODEN);
    }
    else if (s == "STONE_SWORD")
    {
        StoneType STONE;
        return new Sword(STONE);
    }
    else if (s == "IRON_SWORD")
    {
        IronType IRON;
        return new Sword(IRON);
    }
    else if (s == "DIAMOND_SWORD")
    {
        DiamondType DIAMOND;
        return new Sword(DIAMOND);
    }
    else if (s == "WOODEN_PICKAXE")
    {
        WoodenType WOODEN;
        return new Pickaxe(WOODEN);
    }
    else if (s == "STONE_PICKAXE")
    {
        StoneType STONE;
        return new Pickaxe(STONE);
    }
    else if (s == "IRON_PICKAXE")
    {
        IronType IRON;
        return new Pickaxe(IRON);
    }
    else if (s == "DIAMOND_PICKAXE")
    {
        DiamondType DIAMOND;
        return new Pickaxe(DIAMOND);
    }
    return 0;
}

int StringToInt(string ID)
{
    int ans = 0;
    int mul = 1;
    int n = ID.size();
    for (int i = n - 1; i > 0; i--)
    {
        ans += (ID[i] - '0') * mul;
        mul *= 10;
    }
    return ans;
}
#endif