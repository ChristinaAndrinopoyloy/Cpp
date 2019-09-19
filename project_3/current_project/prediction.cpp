#include "prediction.h"

void prediction(dataset &mydata, coins &mycoins, int number_of_best)
{
    double denom, z, R;
    vector<double> temp(mydata.get_point_dimension(), 0.0);
    pair<int, double> initial;
    initial = make_pair(-1, 500);
    vector<pair<unsigned int, double>> best_cryptos(number_of_best);
    string found_value;

    for (int i = 0; i < mydata.get_number_of_points(); i++)
    {
        if (!mydata.get_data(i).get_myneighboors().empty())
        {
            denom = 0.0;
            for (unsigned int j = 0; j < mydata.get_data(i).get_myneighboors().size(); j++) // find z
            {
                denom = denom + mydata.get_data(i).get_myneighboor(j).first;
            }
            z = 1 / denom;
            for (unsigned int k = 0; k < mydata.get_data(i).get_point().second.size(); k++)
            {
                if (mydata.get_data(i).get_point().second[k] == 0.0)
                {
                    for (unsigned int m = 0; m < mydata.get_data(i).get_myneighboors().size(); m++) // find R
                    {
                        R = R + mydata.get_data(i).get_myneighboor(m).first * mydata.get_data(i).get_myneighboor(m).second.get_point().second[k];
                    }
                    R = z * R;
                    temp[k] = R;
                }
            }
            mydata.get_point_to_data(i)->set_recommendation(temp); // find btc, btm, kmd etc.
            for (unsigned int m = 0; m < best_cryptos.size(); m++)
            {
                best_cryptos[m] = initial;
            }
            for (unsigned int m = 0; m < temp.size(); m++)
            {
                for (unsigned int l = 0; l < best_cryptos.size(); l++)
                {
                    if (temp[m] < best_cryptos[l].second && temp[m] != 0.0)
                    {
                        best_cryptos[l] = make_pair(m, temp[m]);
                        break;
                    }
                }
            }
            for (unsigned mm = 0; mm < best_cryptos.size(); mm++)
            {
                mycoins.search_byvalue(best_cryptos[mm].first, found_value);
                mydata.get_point_to_data(i)->set_best_cryptos(found_value);
            }
        }
    }
    return;
}

//set at data the neighboors = points of cluster
void prediction_cluster_prepare(dataset &mydata, vector<cluster> &myclusters)
{
    double dist;
    vector<pair<double, mypoint>> temp;

    for (unsigned int i = 0; i < myclusters.size(); i++)
    {
        for (int j = 0; j < myclusters[i].get_number_of_points(); j++) //for each data of cluster
        {
            for (int n = 0; n < mydata.get_number_of_points(); n++) //for each data
            {
                if (mydata.get_data(n).get_point().first == myclusters[i].get_data(j).get_point().first)
                {
                    for (int k = 0; k < myclusters[i].get_number_of_points(); k++)
                    {
                        if (k != j)
                        {
                            dist = compute_distance(myclusters[i].get_data(j).get_point().second, myclusters[i].get_data(k).get_point().second, mydata);
                            temp.push_back(make_pair(dist, myclusters[i].get_data(k)));
                        }
                    }
                    mydata.get_point_to_data(n)->set_myneighboors(temp);
                    break;
                }
            }
        }
    }
    return;
}