#ifndef _NN_H_
#define _NN_H_

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <sstream>
#include <limits>
#include <algorithm>
#include "dataset.h"
#include "LSH.h"
#include "mymath.h"
#include "hash_helper.h"
#include "cluster.h"
#include "edges.h"
#include "myMap.h"
#include "hypercube.h"

using namespace std;

typedef unordered_multimap<string, myvalue> HashTable;

cluster NN_LSH(double c, int L, vector<HashTable> hashtable, dataset &centroids, int order, int k);
cluster NN_hypercube(double c, int M, int probes, dataset &centroids, int order, vector<edge> &myhybercube, int k, string method, int R, myMap &mymap);

#endif