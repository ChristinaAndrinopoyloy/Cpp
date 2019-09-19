#ifndef _HYPERCUBE_H_
#define _HYPERCUBE_H_

#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <iterator>
#include <map>
#include "edges.h"
#include "dataset.h"
#include "LSH.h"
#include "myMap.h"

using namespace std;

vector<edge> hypercube(dataset &mydata, string method, int k, myMap &mymap);
int mapping_the_h(int h, myMap &mymap);

#endif