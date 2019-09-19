#include "neighboor.h"

void neighboor_routine(dataset &mydata, dataset &myquery)
{
    int L = 3;
    int k = 4;
    int R = 20;
    vector<double> mm;
    vector<double> myneighboors;
    vector<pair<double, mypoint>> res_vec;
    int i;
    vector<HashTable> hashtable(L);

    srand((unsigned)time(NULL));
    myquery.set_method(mydata.get_method());
    for (i = 0; i < L; i++) //make L hashtables
    {
        hashtable[i] = LSH(mydata, mydata.get_method());
    }
    for (int i = 0; i < myquery.get_number_of_points(); i++) //for each query
    {
        res_vec = NN_routine(1, 300, L, hashtable, myquery, i, k, R); //check for neighboors with KNN
        if (!res_vec.empty())
        {
            myquery.get_point_to_data(i)->set_myneighboors(res_vec);
        }
    }
    return;
}