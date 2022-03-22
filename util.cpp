#include "util.hpp"

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
                int cnt=0;
                for (int i = 0; i < n; i++)
                {
                    if (line[i] == ' '){
                        cnt++;
                        continue;
                    }
                    ret += line[i];
                }
                for(;cnt<2;cnt++){
                    ret+="-";
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
        return new Log<Oak>(OAK, num);
    }
    else if (s == "SPRUCE_LOG")
    {
        Spruce SPRUCE;
        return new Log<Spruce>(SPRUCE, num);
    }
    else if (s == "BIRCH_LOG")
    {
        Birch BIRCH;
        return new Log<Birch>(BIRCH, num);
    }
    else if (s == "OAK_PLANK")
    {
        Oak OAK;
        return new Plank<Oak>(OAK, num);
    }
    else if (s == "SPRUCE_PLANK")
    {
        Spruce SPRUCE;
        return new Plank<Spruce>(SPRUCE, num);
    }
    else if (s == "BIRCH_PLANK")
    {
        Birch BIRCH;
        return new Plank<Birch>(BIRCH, num);
    }
    else if (s == "STICK")
    {
        return new Stick(num);
    }
    else if (s == "COBBLESTONE")
    {
        Cobblestone COBBLESTONE;
        return new Stone<Cobblestone>(COBBLESTONE, num);
    }
    else if (s == "BLACKSTONE")
    {
        Blackstone BLACKSTONE;
        return new Stone<Blackstone>(BLACKSTONE, num);
    }
    else if (s == "WOODEN_AXE")
    {
        WoodenType WOODEN;
        return new Axe<WoodenType>(WOODEN);
    }
    else if (s == "STONE_AXE")
    {
        StoneType STONE;
        return new Axe<StoneType>(STONE);
    }
    else if (s == "IRON_AXE")
    {
        IronType IRON;
        return new Axe<IronType>(IRON);
    }
    else if (s == "DIAMOND_AXE")
    {
        DiamondType DIAMOND;
        return new Axe<DiamondType>(DIAMOND);
    }
    else if (s == "WOODEN_SWORD")
    {
        WoodenType WOODEN;
        return new Sword<WoodenType>(WOODEN);
    }
    else if (s == "STONE_SWORD")
    {
        StoneType STONE;
        return new Sword<StoneType>(STONE);
    }
    else if (s == "IRON_SWORD")
    {
        IronType IRON;
        return new Sword<IronType>(IRON);
    }
    else if (s == "DIAMOND_SWORD")
    {
        DiamondType DIAMOND;
        return new Sword<DiamondType>(DIAMOND);
    }
    else if (s == "WOODEN_PICKAXE")
    {
        WoodenType WOODEN;
        return new Pickaxe<WoodenType>(WOODEN);
    }
    else if (s == "STONE_PICKAXE")
    {
        StoneType STONE;
        return new Pickaxe<StoneType>(STONE);
    }
    else if (s == "IRON_PICKAXE")
    {
        IronType IRON;
        return new Pickaxe<IronType>(IRON);
    }
    else if (s == "DIAMOND_PICKAXE")
    {
        DiamondType DIAMOND;
        return new Pickaxe<DiamondType>(DIAMOND);
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