#ifndef _ASSIGNMENT_H_
#define _ASSIGNMENT_H_

#include <vector>
#include <utility>
#include <iostream>
#include "dataset.h"
#include "mymath.h"
#include "cluster.h"
#include "LSH.h"
#include "hypercube.h"
#include "NN.h"
#include "edges.h"
#include "hash_helper.h"
#include "myMap.h"

using namespace std;

vector<cluster> assignment(int assignment_method, int method, dataset &mydata, dataset &centroids, vector<HashTable> &hashtable, vector<edge> &myhypercube, myMap &mymap, int k, int L);
vector<cluster> Lloyd(dataset &mydata, dataset &centroids);
vector<cluster> assignment_by_range(int method, dataset &mydata, dataset &centroids, vector<HashTable> &hashtable, vector<edge> &myhypercube, myMap &mymap, int k, int L);
double find_smallest_distance(dataset &centroids);
double find_bigger_distance(dataset &centroids);
unsigned int find_cluster(int ID, vector<cluster> clusters);
void bruteforce_checking(dataset &mydata, dataset &centroids);

#endif