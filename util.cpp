#include "util.hpp"

void readConfig(map<pair<string, int>, pair<string,int>> &recipe, map<string, tuple<int, string, string>> &itemConfig)
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
        int ans=0;

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
                ans++;
                for (int i = 0; i < n; i++)
                {
                    if (line[i] == ' '){
                        cnt++;
                        ans++;
                        continue;
                    }else if(line[i] == '-'){
                        ans--;
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
        recipe[{infoItem, num}] = {ret,ans};
    }

    // Read item.txt
    ifstream itemConfigFile(configPath + "/item.txt");
    for (string line; getline(itemConfigFile, line);) 
    {
        int start = 0;
        int end = line.find(" ");
        string data[4];
        int i = 0;
        while (end != -1) {
            data[i] = line.substr(start, end - start);
            start = end + 1;
            end = line.find(" ", start);
            i++;
        }
        data[i] = line.substr(start, end - start);
        itemConfig[data[1]] = {stoi(data[0]), data[2], data[3]};
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
    else if (s == "LADDER")
    {
        return new Ladder(num);
    }
    else if (s == "STRING")
    {
        return new String(num);
    }
    else if (s == "FISHING_ROD")
    {
        return new FishingRod(num);
    }
    else
    {
        throw new InvalidItemException();
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
        if(ID[i]-'0'<0 || ID[i]-'0'>9){
            throw new IDException();
        }
        ans += (ID[i] - '0') * mul;
        mul *= 10;
    }
    if(ID[0]!='I' && ID[0]!='C'){
        throw new IDException();
    }
    if(ID[0]=='I' && ans>=27){
        throw new IDException();
    }
    if(ID[0]=='C' && ans>=9){
        throw new IDException();
    }
    return ans;
}

string cutString(string s){
    bool found = false;
    int i = 0;
    while (i < 9 && !found){
        if (s[i] != '-'){
            found = true;
            s = s.substr(i);
        } 
        i++;
    }

    int stringsize = s.size();
    i = stringsize - 1;
    found = false;
    while (i >= 0 && !found){
        if (s[i] != '-'){
            found = true;
            s = s.substr(0,i+1);
        } 
        i--;
    }

    return s;
}