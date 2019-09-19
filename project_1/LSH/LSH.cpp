#include "LSH.h"
#include <algorithm>

/* make the hashing*/
unordered_multimap<string, myvalue> LSH(dataset &mydata, string method)
{
    HashTable hashtable;
    int i;
    vector<int> g;
    stringstream result;
    myvalue mv;

    hashtable.max_load_factor(mydata.get_number_of_points() / sqrt(mydata.get_number_of_points())); //load factor

    for (i = 0; i < mydata.get_number_of_points(); i++)
    {
        g = generate_g_hashfunction(mydata, 4, i, method);
        copy(g.begin(), g.end(), ostream_iterator<int>(result));
        mv.set_point(mydata.get_data(i));
        mv.set_itemID(i);
        hashtable.insert(make_pair(result.str(), mv));
        g.clear();
        result.str(string());
    }

    return hashtable;
}

vector<int> generate_g_hashfunction(dataset &mydata, int k, int order, string method)
{
    int i;
    vector<int> g;

    if (method == "euclidean")
    {
        for (i = 0; i < k; i++)
        {
            g.push_back(generate_Euclidean_h_function(mydata, order));
        }
    }
    else
    {
        for (i = 0; i < k; i++)
        {
            g.push_back(generate_Cosine_h_function(mydata, order));
        }
    }

    return g;
}

/*generate an h function (Euklidean way)*/
int generate_Euclidean_h_function(dataset &mydata, int order)
{
    int w = 4;
    float t;
    vector<float> v(mydata.get_point_dimension());
    int h;

    t = rand() % 4;                                                                                               //t at [0,w)
    v = generate_vector_normalDistribution(mydata.get_point_dimension());                                         //v ~ N(0,1)
    h = (float_vector_multiplication((*mydata.get_data(order)), v, mydata.get_point_dimension()) + t) / (float)w; //let's h = (pv + t)/w

    return h;
}

/*generate an h function (Cosine way)*/
int generate_Cosine_h_function(dataset &mydata, int order)
{
    vector<float> r(mydata.get_point_dimension());

    r = generate_vector_normalDistribution(mydata.get_point_dimension());
    if (float_vector_multiplication(*(mydata.get_data(order)), r, mydata.get_point_dimension()) >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
