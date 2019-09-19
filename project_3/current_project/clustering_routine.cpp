#include "clustering_routine.h"

myMap mymap;
vector<int> vector_assignment(vector<cluster> &clusters);

void clustering_routine(dataset &mydata, vector<cluster> &clusters, int number_of_clusters)
{
    dataset centroids;
    int iterations = 0;
    int max_iterations = 4;
    //   bool continue_flag = true;
    int virtual_ID, number_of_clusterss;
    int initialization_method, assign, assign_method, update_method;
    int number_of_hashfunctions, number_of_hashtables;
    vector<edge> myhypercube;
    vector<double> silhouttes;
    srand((unsigned)time(NULL));

    ofstream file_("THE_OUTPUT");
    interaction_with_user(initialization_method, assign, assign_method, update_method);                 // user selects intialization, assignment, update
    read_from_conf("cluster.conf", number_of_clusterss, number_of_hashfunctions, number_of_hashtables); //read configurations

    vector<HashTable> hashtable(number_of_hashtables);
    virtual_ID = mydata.get_number_of_points();

    for (int i = 0; i < number_of_hashtables; i++) //make L hashtables
    {
        hashtable[i] = LSH(mydata, mydata.get_method());
    }

    centroids = initialization(initialization_method, number_of_clusters, mydata);   // initialize the centroids of algorithm
    vector<int> previous_number_of_cluster_points(centroids.get_number_of_points()); // two vectors for..
    vector<int> current_number_of_cluster_points(centroids.get_number_of_points());  // ..checking for changes at clusters
    do
    {
        clusters = assignment(assign, assign_method, mydata, centroids, hashtable, myhypercube, mymap, number_of_hashfunctions, number_of_hashtables); // assign points at current centroids
        update(update_method, clusters, mydata, centroids, virtual_ID);
        // change centers
        //     current_number_of_cluster_points = vector_assignment(clusters);
        //    if (previous_number_of_cluster_points == current_number_of_cluster_points) // if there are changes continue..
        //  {
        //    continue_flag = false;
        //}
        //   previous_number_of_cluster_points = vector_assignment(clusters);
        mydata.clear_dataset();
        //} while (continue_flag);
        iterations++;
    } while (iterations < max_iterations);
    cout << "End of program" << endl;
}

/* couts of program */
void interaction_with_user(int &initialization_method, int &assign, int &assign_method, int &update_method)
{
    /*    cout << "------------- "
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
    assign = 3;
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
    update_method = 6;
    cin >> update_method;*/
    initialization_method = 0;
    assign = 3;
    assign_method = assign;
    update_method = 6;
}