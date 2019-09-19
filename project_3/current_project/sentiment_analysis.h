#ifndef _SENTIMENT_ANALYSIS_H_
#define _SENTIMENT_ANALYSIS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <limits>
#include <map>
#include "tweets.h"

using namespace std;

class lexicon
{
private:
    map<string, double> Lexicon;
public:
    lexicon();
    ~lexicon();
    map<string, double> *get_lexicon();
    void set_word_of_lexicon(string word, double sentiment);
    void build_sentiment_lexicon(string lexicon_file);
};

double compute_sentiment(double total_score);
void sentiment_analysis(twits &mytwits);

#endif