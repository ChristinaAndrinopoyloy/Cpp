#ifndef _UPDATE_H_
#define _UPDATE_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include "cluster.h"
#include "dataset.h"
#include "mymath.h"

using namespace std;

void update(int method_of_update, vector<cluster> &clusters, dataset &mydata, dataset &centroids, int &virtual_ID);
bool sort_by_distance(pair<mypoint,double> &p1, pair<mypoint,double> &p2) ;

#endif