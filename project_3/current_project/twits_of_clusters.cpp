#include "twits_of_clusters.h"

vector<mypoint> twits_of_clusters(vector<cluster> &myclusters, twits &mytwits)
{
    double sentiment;
    vector<double> temp(100, 0.0);
    int id = 0;
    mypoint temp_point;
    vector<mypoint> new_users;

    for (unsigned int i = 0; i < myclusters.size(); i++)
    {
        for (int j = 0; j < myclusters[i].get_number_of_points(); j++)
        {
            for (unsigned int k = 0; k < mytwits.get_twits().size(); k++)
            {
                if (mytwits.get_twits()[k].get_userID() == myclusters[i].get_data(j).get_point().first)
                {
                    sentiment = mytwits.get_twits()[k].get_sentiment();

                    for (unsigned int n = 0; n < mytwits.get_twits()[k].get_mentioned_cryptos().size(); n++)
                    {
                        temp[mytwits.get_twits()[k].get_mentioned_cryptos()[n].second] = temp[mytwits.get_twits()[k].get_mentioned_cryptos()[n].second] + sentiment;
                    }
                }
            }
        }
        id--;
        temp_point.set_point(make_pair(id, temp));
        new_users.push_back(temp_point);
        myclusters[i].set_c_vector(make_pair(id, temp));
        vector<double> temp(100, 0.0);
    }

    return new_users;
}