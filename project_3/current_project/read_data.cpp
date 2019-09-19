#include "read_data.h"

/*open file, read file and make a dataset*/
void read_data(string file_to_open, twits &mytwits, lexicon &mylexicon, coins &mycoins)
{
    ifstream file;
    string line, neighboors;
    int dimension = 0;
    neighboors.clear();
    point twit;
    file.open(file_to_open);

    if (file.is_open())
    {
        getline(file, line);
        neighboors = line;

        mytwits.set_number_of_nearest_neighboors(stoi(neighboors));

        while (getline(file, line))
        {
            twit = split(line, '\t', dimension, mylexicon, mycoins);
            mytwits.set_data(twit);
            dimension = 0;
        }
    }
    else
    {
        cout << "The file NOT FOUND!" << endl;
        return;
    }

    file.close();

    return;
}

/*from file's line to vector by spliting*/
point split(string &line, char del, int &dimension, lexicon &mylexicon, coins &mycoins)
{
    point twit;
    string token;
    istringstream tokenStream(line);
    double total_score = 0.0;

    while (getline(tokenStream, token, del))
    {
        if (dimension == 0)
        {
            twit.set_userID(stoi(token));
        }
        else if (dimension == 1)
        {
            twit.set_twitID(stoi(token));
        }
        else
        {
            twit.set_twit_point(token);
            map<string, double>::iterator ele = mylexicon.get_lexicon()->find(token); // sentiment analysis preparation
            if (ele != mylexicon.get_lexicon()->end())
            {
                total_score = total_score + ele->second;
            }
            auto ele2 = mycoins.get_coins().find(token);
            if (ele2 != mycoins.get_coins().end())
            {
                twit.set_mentioned_cryptos(ele2->second.first, ele2->second.second);
            }
        }
        dimension++;
    }
    twit.set_sentiment(total_score);
    return twit;
}

void remove_duplicates(dataset &mydata)
{
    for (int j = 0; j < mydata.get_number_of_points(); j++)
    {
        for (int i = j + 1; i < mydata.get_number_of_points(); i++)
        {
            if (mydata.get_data(j).get_point().second == mydata.get_data(i).get_point().second)
            {
                mydata.remove_pair(i);
                i = j;
            }
        }
    }
}

/*open file, read file and make a dataset*/
void read_from_conf(string file_to_open, int &number_of_clusters, int &number_of_hashfunctions, int &number_of_hashtables)
{
    ifstream file;
    string value;
    vector<int> lines_from_conf;

    file.open(file_to_open);
    if (file.is_open())
    {
        while (getline(file, value))
        {
            lines_from_conf.push_back(stoi(value.substr(value.find(":") + 1)));
        }
    }
    else
    {
        cout << "The .conf file NOT FOUND!" << endl;
        return;
    }
    file.close();

    number_of_clusters = lines_from_conf[0];
    number_of_hashfunctions = lines_from_conf[1];
    number_of_hashtables = lines_from_conf[2];
    
    return;
}