#ifndef _COINS_H_
#define _COINS_H_

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;


class coins
{
private:
    map<string,pair<string,int>> Coins;
public:
    coins();
    ~coins();
    map<string,pair<string,int>> get_coins();
    void set_coins(string key, string value, int order);
    void build_coin_lexicon(string lexicon_file);
    void search_byvalue(int value, string &found_value);
};

#endif