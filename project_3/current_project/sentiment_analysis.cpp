#include "sentiment_analysis.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*constructor - destructor*/
lexicon::lexicon()
{
}

lexicon::~lexicon()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*getters - setters*/
map<string, double> *lexicon::get_lexicon()
{
    return &Lexicon;
}
/*
pair<string, double> lexicon::get_word_of_lexicon(int order)
{
    return Lexicon[order];
}*/
void lexicon::set_word_of_lexicon(string word, double sentiment)
{
    Lexicon.insert({word, sentiment});
}

void lexicon::build_sentiment_lexicon(string lexicon_file)
{
    ifstream file;
    string line;
    string token;
    string temp_word;
    char delimeter = '\t';
    bool isword = 1;

    file.open(lexicon_file);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            istringstream tokenStream(line);
            while (getline(tokenStream, token, delimeter))
            {
                if (isword)
                {
                    temp_word = token;
                    isword = 0;
                }
                else
                {
                    Lexicon.insert({temp_word, stod(token)});
                    isword = 1;
                }
            }
        }
    }
    else
    {
        cout << "The file NOT FOUND!" << endl;
        return;
    }

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double compute_sentiment(double total_score)
{
    double denominator;
    double sentiment;
    denominator = total_score * total_score;
    denominator = denominator + 15;
    sentiment = total_score / sqrt(denominator);
    return sentiment;
}

void sentiment_analysis(twits &mytwits)
{
    double total_score, sentiment;

    for (unsigned int i = 0; i < mytwits.get_twits().size(); i++)
    {
        total_score = mytwits.get_twits()[i].get_sentiment();
        if (total_score != numeric_limits<double>::infinity())
        {
            sentiment = compute_sentiment(total_score);
            mytwits.get_point_to_data(i)->set_sentiment(sentiment);
        }
    }
    return;
}