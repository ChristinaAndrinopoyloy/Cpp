#include "bruteforce.h"

/* returns the best neighboor*/
nearest_point bruteforce(vector<int> point, dataset &mydata)
{
    int i;
    float min_distance, distance;
    vector<int> data;
    int min_point;
    nearest_point np;

    data = *(mydata.get_data(0));

    min_point = 0;

    min_distance = compute_distance(point, *(mydata.get_data(0)), mydata);
    for (i = 1; i < mydata.get_number_of_points(); i++) //bruteforce
    {
        distance = compute_distance(point, *(mydata.get_data(i)), mydata);
        if (distance < min_distance)
        {
            min_point = i;
            min_distance = distance;
        }
    }

    np.set_min_point(min_point);
    np.set_distance(min_distance);
    return np;
}