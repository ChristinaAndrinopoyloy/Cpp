#include "hypercube.h"

vector<edge> hypercube(dataset &mydata, string method, int k, myMap &mymap)
{
    vector<edge> myhypercube(pow(2, k));
    vector<int> id;
    int h, empty_index;
    bool b;
    bool flag = 0; //find or not point at a "bucket"
    stringstream key;

    for (int i = 0; i < mydata.get_number_of_points(); i++) //for each data
    {
        flag = 0;
        for (int j = 0; j < k; j++)
        {
            if (method == "euclidean")
            {
                h = generate_Euclidean_h_function(&mydata, i);
                b = mapping_the_h(h, mymap);
                id.push_back(b);
            }
            else //no mapping, because h at {0,1}
            {
                h = generate_Cosine_h_function(&mydata, i);
                id.push_back(h);
            }
        }
        copy(id.begin(), id.end(), ostream_iterator<int>(key));
        for (int m = 0; m < pow(2, k); m++)
        {
            if (myhypercube[m].get_id() == key.str()) //it's already here the "key"
            {
                flag = 1;
                myhypercube[m].set_point(mydata.get_point_to_data(i));
            }
            else //attemp to find empty "bucket"
            {
                if (myhypercube[m].get_id() == "none")
                {
                    empty_index = m;
                }
            }
        }
        if (flag == 0) //let's put a new "key" and "value" at an empty "bucket"
        {
            myhypercube[empty_index].set_id(key.str());
            myhypercube[empty_index].set_point(mydata.get_point_to_data(i));
        }
        id.clear();
        key.str(string());
    }  
    return myhypercube;
}

/* every h (number) takes a bool value consistent*/
int mapping_the_h(int h, myMap &mymap)
{
    myMap::iterator it;
    int coin;

    it = mymap.find(h);
    if (it != mymap.end()) //it's already here
    {
        coin = it->second;
    }
    else //random - coin
    {
        coin = rand() % 2;
        mymap.insert(make_pair(h, coin));
    }
    return coin;
}