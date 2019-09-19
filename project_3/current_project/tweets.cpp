#include "tweets.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*constructor - destructor*/
point::point()
{
    sentiment = numeric_limits<double>::infinity();
}

point::~point()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*getters - setters*/
int point::get_userID()
{
    return userID;
}

void point::set_userID(int setID)
{
    userID = setID;
}

int point::get_twitID()
{
    return twitID;
}

void point::set_twitID(int setID)
{
    twitID = setID;
}

vector<string> point::get_twit_point()
{
    return twit_point;
}

void point::set_twit_point(string setpoint)
{
    twit_point.push_back(setpoint);
}

double point::get_sentiment()
{
    return sentiment;
}

void point::set_sentiment(double set_s)
{
    sentiment = set_s;
}

vector<pair<string,int>> point::get_mentioned_cryptos()
{
    return mentioned_cryptos;
}

void point::set_mentioned_cryptos(string crypto, int order)
{
    mentioned_cryptos.push_back(make_pair(crypto, order));
}

void point::remove_duplicates_mentioned_cryptos()
{
    sort(mentioned_cryptos.begin(), mentioned_cryptos.end());
    auto it = std::unique(mentioned_cryptos.begin(), mentioned_cryptos.end());
    mentioned_cryptos.erase(it, mentioned_cryptos.end());
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*constructor - destructor*/
twits::twits()
{
}

twits::~twits()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*getters - setters*/
vector<point> twits::get_twits()
{
    return Twits;
}

point *twits::get_point_to_data(int order)
{
    return &(Twits[order]);
}

void twits::set_data(point v)
{
    Twits.push_back(v);
}

int twits::get_number_of_nearest_neighboors()
{
    return number_of_nearest_neighboors;
}

void twits::set_number_of_nearest_neighboors(int set_number)
{
    number_of_nearest_neighboors = set_number;
}