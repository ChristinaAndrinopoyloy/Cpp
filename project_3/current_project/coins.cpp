#include "coins.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*constructor - destructor*/
coins::coins()
{
}

coins::~coins()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*getters - setters*/
map<string, pair<string, int>> coins::get_coins()
{
    return Coins;
}

void coins::set_coins(string key, string value, int order)
{
    Coins.insert(make_pair(key, make_pair(value, order)));
}

void coins::build_coin_lexicon(string lexicon_file)
{
    ifstream file;
    string line;
    string token;
    string temp_word;
    char delimeter = '\t';
    bool iskey = 1;
    int counter = 0;

    file.open(lexicon_file);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            istringstream tokenStream(line);
            while (getline(tokenStream, token, delimeter))
            {
                if (iskey)
                {
                    temp_word = token;
                    iskey = 0;
                }
                else
                {
                    Coins.insert(make_pair(token, make_pair(temp_word, counter)));
                }
            }
            iskey = 1;
            counter++;
        }
    }
    else
    {
        cout << "The file NOT FOUND!" << endl;
        return;
    }
    return;
}

void coins::search_byvalue(int value, string &found_value)
{
    bool found = false;

    std::for_each(Coins.begin(), Coins.end(),
                  [&value, &found, &found_value](const std::pair<string, pair<string, int>> &p) {
                        
                      if (p.second.second == value)
                      {
                          found_value = p.second.first;
                          found = true;
                      }
                  });
    return;
}