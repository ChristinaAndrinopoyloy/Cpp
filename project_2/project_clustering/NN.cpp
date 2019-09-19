#include "NN.h"

cluster NN_LSH(double c, int L, vector<HashTable> hashtable, dataset &centroids, int order, int k)
{
    cluster mycluster;
    vector<int> g;
    stringstream key;
    double distance;

    mycluster.set_representer(centroids.get_data(order));

    for (int j = 0; j < L; j++) //for each hashtable
    {
        g.clear();
        key.str(string());
        g = generate_g_hashfunction(&centroids, k, order, centroids.get_method());
        copy(g.begin(), g.end(), ostream_iterator<int>(key));

        for (auto it = hashtable[j].begin(hashtable[j].bucket(key.str())); it != hashtable[j].end(hashtable[j].bucket(key.str())); ++it) //check at the query's bucket
        {
            distance = compute_distance((*(it->second).get_point()).get_point().second, centroids.get_data(order).get_point().second, centroids);
            if (distance <= c)
            {
                if ((*(it->second).get_point()).get_checked() == 0)
                {
                    (*(it->second).get_point()).set_checked(1);
                    (*(it->second).get_point()).set_distance(distance);
                    (*(it->second).get_point()).set_ID_of_cluster(mycluster.get_representer().get_point().first);
                }
                else
                {
                    if (distance < (*(it->second).get_point()).get_distance())
                    {
                        (*(it->second).get_point()).set_distance(distance);
                        (*(it->second).get_point()).set_ID_of_cluster(mycluster.get_representer().get_point().first);
                    }
                }
            }
        }
    }
    return mycluster;
}

cluster NN_hypercube(double c, int M, int probes, dataset &centroids, int order, vector<edge> &myhybercube, int k, string method, int R, myMap &mymap)
{
    cluster mycluster;
    int h;
    int b;
    vector<int> id_vec;
    stringstream key;
    double distance;

    mycluster.set_representer(centroids.get_data(order));

    if (method == "euclidean")
    {
        for (int j = 0; j < k; j++)
        {
            h = generate_Euclidean_h_function(&centroids, order);
            b = mapping_the_h(h, mymap);
            id_vec.push_back(b);
        }
    }
    else //no mapping, because h at {0,1}
    {
        for (int j = 0; j < k; j++)
        {
            h = generate_Cosine_h_function(&centroids, order);
            id_vec.push_back(h);
        }
    }
    copy(id_vec.begin(), id_vec.end(), ostream_iterator<int>(key));

    for (int m = 0; m < probes; m++) //hamming distances
    {
        for (unsigned int i = 0; i < myhybercube.size(); i++)
        {
            if (hammingDistance(key.str(), myhybercube[i].get_id()) == m)
            {
                if (M > myhybercube[i].get_size())
                {
                    M = myhybercube[i].get_size();
                }
                for (int n = 0; n < M; n++)
                {
                    distance = compute_distance(myhybercube[i].get_point(n)->get_point().second, centroids.get_data(order).get_point().second, centroids);
                    if (distance <= c)
                    {
                        if (myhybercube[i].get_point(n)->get_checked() == 0)
                        {
                            myhybercube[i].get_point(n)->set_checked(1);
                            myhybercube[i].get_point(n)->set_distance(distance);
                            myhybercube[i].get_point(n)->set_ID_of_cluster(mycluster.get_representer().get_point().first);
                        }
                        else
                        {
                            if (distance < myhybercube[i].get_point(n)->get_distance())
                            {
                                myhybercube[i].get_point(n)->set_distance(distance);
                                myhybercube[i].get_point(n)->set_ID_of_cluster(mycluster.get_representer().get_point().first);
                            }
                        }
                    }
                }
            }
        }
    }
    return mycluster;
}