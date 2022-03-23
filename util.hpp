/* File: util.hpp */
#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <list>
#include <tuple>
#include "Item/Axe.hpp"
#include "Item/Diamond.hpp"
#include "Item/IronIngot.hpp"
#include "Item/IronNugget.hpp"
#include "Item/Item.hpp"
#include "Item/Log.hpp"
#include "Item/nonTool.hpp"
#include "Item/nonToolType.hpp"
#include "Item/Pickaxe.hpp"
#include "Item/Plank.hpp"
#include "Item/Stick.hpp"
#include "Item/Stone.hpp"
#include "Item/Sword.hpp"
#include "Item/Tool.hpp"
#include "Item/ToolType.hpp"

using namespace std;

void readConfig(map<pair<string, int>, string> &recipe, map<string, tuple<int, string, string>> &itemConfig);

Item *getItemFromString(string s, int num);

int StringToInt(string ID);

string cutString(string recipe);
#endif