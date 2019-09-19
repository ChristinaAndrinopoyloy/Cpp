#ifndef _NN_H_
#define _NN_H_

#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include "dataset.h"
#include "LSH_part.h"
#include "mymath.h"
#include "edges.h"
#include "hypercube.h"
#include "myMap.h"

using namespace std;

vector<pair<float, int>> NN(int c, int r, int M, int probes, dataset &myqueries, int order, vector<edge> &myhybercube, int k, string method, int R, myMap &mymap);

#endif