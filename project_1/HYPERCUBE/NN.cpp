#include "NN.h"

vector<pair<float, int>> NN(int c, int r, int M, int probes, dataset &myqueries, int order, vector<edge> &myhybercube, int k, string method, int R, myMap &mymap)
{
    unsigned int i;
    int j, m, n, h;
    int b;
    vector<int> id_vec;
    vector<pair<float, int>> myneighboors;
    stringstream key;
    float distance;

    if (method == "euclidean")
    {
        for (j = 0; j < k; j++)
        {
            h = generate_Euclidean_h_function(myqueries, order);
            b = mapping_the_h(h, mymap);
            id_vec.push_back(b);
        }
    }
    else //no mapping, because h at {0,1}
    {
        for (j = 0; j < k; j++)
        {
            h = generate_Cosine_h_function(myqueries, order);
            id_vec.push_back(h);
        }
    }
    copy(id_vec.begin(), id_vec.end(), ostream_iterator<int>(key));

    for (m = 0; m < probes; m++) //hamming distances
    {
        for (i = 0; i < myhybercube.size(); i++)
        {
            if (hammingDistance(key.str(), myhybercube[i].get_id()) == m)
            {
                if (M > myhybercube[i].get_size())
                {
                    M = myhybercube[i].get_size();
                }
                for (n = 0; n < M; n++)
                {
                    distance = compute_distance(*(myhybercube[i].get_point(n).second), *(myqueries.get_data(order)), myqueries);
                    if (distance <= c * r)
                    {
                        myneighboors.push_back(make_pair(distance, myhybercube[i].get_point(n).first));
                    }
                }
            }
        }
    }

    sort(myneighboors.begin(), myneighboors.end());
    myneighboors.resize(R);

    return myneighboors;
}