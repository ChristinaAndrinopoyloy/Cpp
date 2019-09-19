#include "initialization.h"

dataset initialization(int method, int number_of_k_points, dataset &mydata)
{
    dataset centroids;

    centroids.set_method(mydata.get_method());
    centroids.set_number_of_points(number_of_k_points);
    centroids.set_point_dimension(mydata.get_point_dimension());
    centroids.set_qinfo(mydata.get_qinfo());

    if (method == 0) // choose random k (number_of_k_points) points
    {
        for (int i = 0; i < number_of_k_points; i++)
        {
            centroids.set_data(select_random_point(mydata));
            mydata.update((centroids.get_data(i)));
        }
    }
    else // initialization++
    {
        int number_of_centroids = 1;
        centroids.set_data(select_random_point(mydata));
        mydata.update((centroids.get_data(0)));
        double distance, random_number;
        double smallest_distance = 10000000;
        double bigger_distance = 0;
        vector<double> partial_sums; // array of partial summs (class implementation)
        vector<double>::iterator up;

        while (number_of_centroids != number_of_k_points) // this loop gives number_of_k_points centroids
        {
            partial_sums.clear();
            for (int i = 0; i < mydata.get_number_of_points(); i++) // for every point except centroids
            {
                for (int j = 0; j < number_of_centroids; j++) // for every centroid
                {
                    distance = compute_distance((mydata.get_data(i).get_point().second), (centroids.get_data(j).get_point().second), mydata);
                    smallest_distance = min(distance, smallest_distance);
                }
                bigger_distance = max(bigger_distance, smallest_distance); // we need biggest distance for normalization
                if (i == 0)
                {
                    partial_sums.push_back(smallest_distance * smallest_distance);
                }
                else
                {
                    partial_sums.push_back(partial_sums[i - 1] + (smallest_distance * smallest_distance));
                }
            }
            for (int n = 0; n < mydata.get_number_of_points(); n++) // normalization
            {
                partial_sums[n] = partial_sums[n] / bigger_distance;
            }
            smallest_distance = 10000000;
            bigger_distance = 0;
            random_number = select_random_number(1, (int)partial_sums[mydata.get_number_of_points() - 1]); // select random number at [0, P(n-t)]
            up = upper_bound(partial_sums.begin(), partial_sums.end(), random_number);                      // select right at partial sums array
            centroids.set_data(mydata.get_data(up - partial_sums.begin()));
            mydata.update((centroids.get_data(number_of_centroids)));
            number_of_centroids = number_of_centroids + 1;
        }
    }
    return centroids;
}

double select_random_number(int myfloor, int myceil)
{
    int temp;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(myfloor, myceil - 1);
    temp = abs(distribution(generator));
    return temp;
}

mypoint select_random_point(dataset mydata)
{
    int ID;
    mypoint point;

    ID = select_random_number(0, mydata.get_number_of_points());
    point = mydata.get_data(ID);
    return point;
}