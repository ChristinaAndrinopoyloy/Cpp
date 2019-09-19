#include "assignment.h"

vector<cluster> assignment(int assignment_method, int method, dataset &mydata, dataset &centroids, vector<HashTable> &hashtable, vector<edge> &myhypercube, myMap &mymap, int k, int L)
{
    vector<cluster> clusters;

    switch (assignment_method)
    {
    case 2: // Lloyd's
        clusters = Lloyd(mydata, centroids);
        break;
    case 3: // Assignment by range (LSH)
        clusters = assignment_by_range(method, mydata, centroids, hashtable, myhypercube, mymap, k, L);
        break;
    case 4: // Assignment by range (Hypercube)
        clusters = assignment_by_range(method, mydata, centroids, hashtable, myhypercube, mymap, k, L);
        break;
    default:
        cout << "ERROR at assignment method!" << endl;
        break;
    }
    return clusters;
}

vector<cluster> Lloyd(dataset &mydata, dataset &centroids)
{
    double distance;
    double smallest_distance = 1000000;
    pair<int, vector<double>> from;
    vector<cluster> clusters; // all clusters in a vector
    cluster temp_cluster;

    for (int n = 0; n < centroids.get_number_of_points(); n++) // initialize all clusters
    {
        temp_cluster.set_representer(centroids.get_data(n));
        clusters.push_back(temp_cluster);
    }

    for (int i = 0; i < mydata.get_number_of_points(); i++) // for every point except centroids
    {
        for (int j = 0; j < centroids.get_number_of_points(); j++) // for every centroid
        {
            distance = compute_distance((mydata.get_data(i).get_point().second), (centroids.get_data(j).get_point().second), mydata); // compute smallest distance
            if (distance < smallest_distance && distance !=0)
            {
                smallest_distance = distance;
                from = centroids.get_data(j).get_point(); // nearest cluster
            }
        }
        smallest_distance = 1000000;
        unsigned int m = 0;
        while (m < clusters.size() && clusters[m].get_representer().get_point().first != from.first)
        {
            m++;
        }
        clusters[m].set_data(mydata.get_data(i)); // assign a point at a suitable cluster
        clusters[m].set_number_of_points(clusters[m].get_number_of_points() + 1);
        m = 0;
    }

    for (unsigned int l = 0; l < clusters.size(); l++)
    {
        cout << clusters[l].get_number_of_points() << " members at cluster with representer " << clusters[l].get_representer().get_point().first << endl;
    }

    return clusters;
}

vector<cluster> assignment_by_range(int method, dataset &mydata, dataset &centroids, vector<HashTable> &hashtable, vector<edge> &myhypercube, myMap &mymap, int k, int L)
{
    int index;
    vector<cluster> clusters(centroids.get_number_of_points()); // all clusters in a vector
    double smallest_distance, bigger_distance;
    int probes = 4;
    int R = 5;
    int M = 10;

    smallest_distance = find_smallest_distance(centroids);
    bigger_distance = find_bigger_distance(centroids);
    switch (method)
    {
    case 3: // LSH
        do
        {
            for (int i = 0; i < centroids.get_number_of_points(); i++)
            {
                clusters[i] = NN_LSH(smallest_distance, L, hashtable, centroids, i, k); //check for neighboors with KNN
            }
            smallest_distance = smallest_distance * 2;
        } while (smallest_distance < bigger_distance);
        break;

    case 4: // HYPERCUBE
        do
        {
            for (int i = 0; i < centroids.get_number_of_points(); i++)
            {
                clusters[i] = NN_hypercube(smallest_distance, M, probes, centroids, i, myhypercube, k, mydata.get_method(), R, mymap); //check for neighboors with KNN
            }
            smallest_distance = smallest_distance * 2;
        } while (smallest_distance < 5 * bigger_distance);
        break;

    default:
        cout << "ERROR at assignment by range method!" << endl;
        break;
    }

    bruteforce_checking(mydata, centroids);
    for (int j = 0; j < mydata.get_number_of_points(); j++)
    {
        index = find_cluster(mydata.get_data(j).get_ID_of_cluster(), clusters);
        clusters[index].set_data(mydata.get_data(j));
        clusters[index].set_number_of_points(clusters[index].get_number_of_points() + 1);
    }

    return clusters;
}

double find_smallest_distance(dataset &centroids)
{
    double distance;
    double smallest_distance = 10000;

    for (int j = 0; j < centroids.get_number_of_points(); j++)
    {
        for (int m = 0; m < centroids.get_number_of_points(); m++)
        {
            if (centroids.get_data(j).get_point().first != centroids.get_data(m).get_point().first)
            {
                distance = compute_distance(centroids.get_data(j).get_point().second, centroids.get_data(m).get_point().second, centroids);
                if (distance < smallest_distance)
                {
                    smallest_distance = distance;
                }
            }
        }
    }
    smallest_distance = smallest_distance / 2;

    return smallest_distance;
}

double find_bigger_distance(dataset &centroids)
{
    double distance;
    double bigger_distance = 0;

    for (int j = 0; j < centroids.get_number_of_points(); j++)
    {
        for (int m = 0; m < centroids.get_number_of_points(); m++)
        {
            if (centroids.get_data(j).get_point().first != centroids.get_data(m).get_point().first)
            {
                distance = compute_distance(centroids.get_data(j).get_point().second, centroids.get_data(m).get_point().second, centroids);
                if (distance > bigger_distance)
                {
                    bigger_distance = distance;
                }
            }
        }
    }
    return bigger_distance;
}

unsigned int find_cluster(int ID, vector<cluster> clusters)
{
    unsigned int i = 0;
    while (i < clusters.size() && ID != clusters[i].get_representer().get_point().first)
    {
        i++;
    }
    return i;
}

void bruteforce_checking(dataset &mydata, dataset &centroids)
{
    double distance;
    for (int i = 0; i < mydata.get_number_of_points(); i++)
    {
        if (mydata.get_data(i).get_checked() == 0)
        {
            for (int j = 0; j < centroids.get_number_of_points(); j++)
            {
                distance = compute_distance(mydata.get_data(i).get_point().second, centroids.get_data(j).get_point().second, centroids);
                if (distance < mydata.get_data(i).get_distance() && distance != 0)
                {
                    mydata.get_point_to_data(i)->set_checked(1);
                    mydata.get_point_to_data(i)->set_distance(distance);
                    mydata.get_point_to_data(i)->set_ID_of_cluster(centroids.get_data(j).get_point().first);
                }
            }
        }
    }
}
