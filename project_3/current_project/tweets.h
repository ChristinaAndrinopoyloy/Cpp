#ifndef _TWEETS_H_
#define _TWEETS_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

class point
{
  private:
    int userID;
    int twitID;
    vector<string> twit_point;
    double sentiment;
    vector<pair<string,int>> mentioned_cryptos;

  public:
    point();
    ~point();
    int get_userID();
    void set_userID(int setID);
    int get_twitID();
    void set_twitID(int setID);
    vector<string> get_twit_point();
    void set_twit_point(string setpoint);
    double get_sentiment();
    void set_sentiment(double set_s);
    vector<pair<string,int>> get_mentioned_cryptos();
    void set_mentioned_cryptos(string crypto, int order);
    void remove_duplicates_mentioned_cryptos();
};

class twits
{
  private:
    vector<point> Twits;
    int number_of_nearest_neighboors;

  public:
    twits();
    ~twits();
    vector<point> get_twits();
    point *get_point_to_data(int order);
    void set_data(point v);
    int get_number_of_nearest_neighboors();
    void set_number_of_nearest_neighboors(int set_number);
};

#endif