#include "NN.h"

vector<pair<float, int>> NN(int r, int c, int L, vector<HashTable> hashtable, dataset myquery, int order, int k, int R)
{
    vector<int> g;
    vector<pair<float, int>> myneighboors;
    stringstream key;
    float distance;

    for (int j = 0; j < L; j++) //for each hashtable
    {
        g.clear();
        key.str(string());
        g = generate_g_hashfunction(myquery, k, order, myquery.get_method());
        copy(g.begin(), g.end(), ostream_iterator<int>(key));

        for (auto it = hashtable[j].begin(hashtable[j].bucket(key.str())); it != hashtable[j].end(hashtable[j].bucket(key.str())); ++it) //check at the query's bucket
        {
            distance = compute_distance((*(it->second).get_point()), *(myquery.get_data(order)), myquery);
            if (distance <= c * r)
            {
                myneighboors.push_back(make_pair(distance, (it->second).get_itemID()));
            }
        }
    }

    sort(myneighboors.begin(), myneighboors.end());
    myneighboors.resize(R);

    return myneighboors;
}