#include <iostream>
#include <vector>
#include <utility>
#include "read_data.h"
#include "dataset.h"
#include "initialization.h"
#include "assignment.h"
#include "cluster.h"
#include "update.h"
#include "LSH.h"
#include "hypercube.h"
#include "hash_helper.h"
#include "evaluation.h"

#define NONE -1
#define LSH_METHOD 4
#define HYPERCUBE_METHOD 5

using namespace std;

myMap mymap;
vector<int> vector_assignment(vector<cluster> &clusters);
void interaction_with_user(int &initialization_method, int &assign, int &assign_method, int &update_method);

int main(int argc, char const *argv[])
{
    dataset mydata;
    dataset centroids;
    vector<cluster> clusters;
    int iterations = 0;
    int max_iterations = 4;
    string path;
    bool continue_flag = true;
    int virtual_ID, complete_flag;
    int initialization_method, assign, assign_method, update_method;
    int number_of_clusters, number_of_hashfunctions, number_of_hashtables;
    vector<edge> myhypercube;
    vector<double> silhouttes;
    double total_time;
    clock_t begin, end;
    srand((unsigned)time(NULL));

    if (argc == 1)
    {
        cout << "INPUT FILE WITH DATA: " << endl;
        cin >> path;
        read_data(path, mydata);
        cout << "OUTPUT FILE:" << endl;
        cin >> path;
    }
    else
    {
        path = argv[2];
        read_data(path, mydata);
        path = argv[4];
        read_from_conf(path, number_of_clusters, number_of_hashfunctions, number_of_hashtables);
        path = argv[6];
        string str;
        str = argv[8];
        complete_flag = stoi(str);
    }
    ofstream file_(path);
    interaction_with_user(initialization_method, assign, assign_method, update_method);                // user selects intialization, assignment, update
    read_from_conf("cluster.conf", number_of_clusters, number_of_hashfunctions, number_of_hashtables); //read configurations

    vector<HashTable> hashtable(number_of_hashtables);
    read_data("small.csv", mydata); //read data from dataset
    virtual_ID = mydata.get_number_of_points();
    remove_duplicates(mydata);       // remove duplicates points of dataset - smaller dataset, less job
    if (assign_method == LSH_METHOD) // data at "buckets" - previous project
    {
        for (int i = 0; i < number_of_hashtables; i++) //make L hashtables
        {
            hashtable[i] = LSH(mydata, mydata.get_method());
        }
    }
    else if (assign_method == HYPERCUBE_METHOD)
    {
        myhypercube = hypercube(mydata, mydata.get_method(), number_of_hashfunctions, mymap); //make the hypercube of data
    }

    begin = clock();
    centroids = initialization(initialization_method, number_of_clusters, mydata);   // initialize the centroids of algorithm
    vector<int> previous_number_of_cluster_points(centroids.get_number_of_points()); // two vectors for..
    vector<int> current_number_of_cluster_points(centroids.get_number_of_points());  // ..checking for changes at clusters
    do
    {
        clusters = assignment(assign, assign_method, mydata, centroids, hashtable, myhypercube, mymap, number_of_hashfunctions, number_of_hashtables); // assign points at current centroids
        update(update_method, clusters, mydata, centroids, virtual_ID);                                                                                // change centers
        current_number_of_cluster_points = vector_assignment(clusters);
        for (unsigned int i = 0; i < clusters.size(); i++)
        {
            cout << "Cluster with representer " << clusters[i].get_representer().get_point().first << " " << centroids.get_data(i).get_point().first << " has " << clusters[i].get_number_of_points() << " members." << endl;
        }
        if (previous_number_of_cluster_points == current_number_of_cluster_points) // if there are changes continue..
        {
            continue_flag = false;
        }
        previous_number_of_cluster_points = vector_assignment(clusters);
        mydata.clear_dataset();
    //} while (continue_flag);
            iterations++;
        } while (iterations < max_iterations);
    end = clock();
    total_time = (double)(end - begin) / CLOCKS_PER_SEC;
    silhouttes = evaluation(mydata, clusters); // silhouette evaluation

    if (file_.is_open())
    {
        file_ << "Algorithm: " << initialization_method << "x" << assign << "x" << update_method << endl;
        file_ << "Metric: " << mydata.get_method() << endl;

        if (update_method == 7)
        {
            for (unsigned int i = 0; i < clusters.size(); i++)
            {
                file_ << "CLUSTER-" << i << " (size: " << clusters[i].get_number_of_points() << ", centroid: " << clusters[i].get_representer().get_point().first << ")" << endl;
            }
        }
        if (update_method == 6)
        {
            for (unsigned int i = 0; i < clusters.size(); i++)
            {
                file_ << "CLUSTER-" << i << " (size: " << clusters[i].get_number_of_points() << ", centroid: ";

                for (unsigned int j = 0; j < clusters[i].get_representer().get_point().second.size(); j++)
                {
                    file_ << clusters[i].get_representer().get_point().second[j] << ", ";
                }
                file_ << endl;
            }
        }

        file_ << "clustering_time: " << total_time << endl;
        file_ << "Silhouette: [";
        for (unsigned int i = 0; i < silhouttes.size(); i++)
        {
            file_ << silhouttes[i] << ",";
        }
        file_ << "]" << endl;

        if (complete_flag == 1)
        {
            for (unsigned int i = 0; i < clusters.size(); i++)
            {
                file_ << "CLUSTER-" << i << " (";
                for (int j = 0; j < clusters[i].get_number_of_points(); j++)
                {
                    file_ << clusters[i].get_data(j).get_point().first << ", ";
                }
                file_ << ")" << endl;
            }
        }
        file_.close();
    }
    cout << "End of program" << endl;
    return 0;
}

/* routine for assign number of points at a vector */
vector<int> vector_assignment(vector<cluster> &clusters)
{
    vector<int> returned_vector;
    for (unsigned int i = 0; i < clusters.size(); i++)
    {
        returned_vector.push_back(clusters[i].get_number_of_points());
    }
    return returned_vector;
}

/* couts of program */
void interaction_with_user(int &initialization_method, int &assign, int &assign_method, int &update_method)
{
    cout << "------------- "
         << "Initialization"
         << " -------------" << endl;
    cout << "Select:" << endl
         << "0 for RANDOM SELECTION OF k POINTS" << endl
         << "1 for K-MEANS++" << endl;
    cin >> initialization_method;
    cout << "--------------- "
         << "Assignment"
         << " ---------------" << endl;
    cout << "Select:" << endl
         << "2 for LLOYD'S ASSIGNMENT" << endl
         << "3 for ASSIGNMENT BY RANGE SEARCH WITH LSH" << endl
         << "4 for ASSIGNMENT BY RANGE WITH HYPERCUBE" << endl;
    cin >> assign;
    if (assign == 2)
    {
        assign_method = NONE;
    }
    else
    {
        assign_method = assign;
    }
    cout << "----------------- "
         << "Update"
         << " -----------------" << endl;
    cout << "Select:" << endl
         << "6 for K-MEANS" << endl
         << "7 for PARTIONING AROUNG MEDOIDS (PAM) LIKE LLOYD'S" << endl;
    cin >> update_method;
}