#include "preprocessing.h"

void preprocess(twits &mytwits, dataset &mydata)
{
    int previous_userID;
    mypoint temp_point;
    int order = 0;
    vector<bool> helpVector;

    for (unsigned int i = 0; i < mytwits.get_twits().size(); i++)
    {
        if (mytwits.get_twits()[i].get_sentiment() != numeric_limits<double>::infinity() && mytwits.get_twits()[i].get_sentiment() != 0.0)
        {
            if (mytwits.get_twits()[i].get_userID() != previous_userID || i == 0)
            {
                vector<double> initial_vec(100, 0.0);
                vector<bool> initial_vec_bool(100, false);
                temp_point.set_point(make_pair(mytwits.get_twits()[i].get_userID(), initial_vec));
                for (unsigned int j = 0; j < mytwits.get_twits()[i].get_mentioned_cryptos().size(); j++)
                {
                    initial_vec[mytwits.get_twits()[i].get_mentioned_cryptos()[j].second] = mytwits.get_twits()[i].get_sentiment();
                    initial_vec_bool[mytwits.get_twits()[i].get_mentioned_cryptos()[j].second] = true;
                }
                temp_point.set_point(make_pair(mytwits.get_twits()[i].get_userID(), initial_vec));
                temp_point.set_is_mentioned(initial_vec_bool);
                if (find(begin(initial_vec_bool), end(initial_vec_bool), false) == end(initial_vec_bool)) // All false
                {
                    if (i == 0)
                    {
                        order = 1;
                    }
                }
                else
                {
                    mydata.set_data(temp_point);
                    order++;
                }
            }
            else
            {
                vector<double> s1(100, 0.0);
                vector<double> sum(100, 0.0);
                vector<double> initial_vec(100, 0.0);
                vector<bool> initial_vec_bool(100, false);
                for (unsigned int j = 0; j < mytwits.get_twits()[i].get_mentioned_cryptos().size(); j++)
                {
                    initial_vec[mytwits.get_twits()[i].get_mentioned_cryptos()[j].second] = mytwits.get_twits()[i].get_sentiment();
                    initial_vec_bool[mytwits.get_twits()[i].get_mentioned_cryptos()[j].second] = true;
                }
                s1 = mydata.get_point_to_data(order - 1)->get_point().second;
                for (unsigned int k = 0; k < 100; k++)
                {
                    sum[k] = s1[k] + initial_vec[k];
                }
                mydata.get_point_to_data(order - 1)->set_point(make_pair(previous_userID, sum));
            }
        }

        previous_userID = mytwits.get_twits()[i].get_userID();
    }
    mydata.set_number_of_points(order);
    mydata.set_method("cosine");
    mydata.set_point_dimension(100);    
    normalize(mydata);
    return;
}