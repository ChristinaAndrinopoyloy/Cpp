#ifndef _PREDICTION_H_
#define _PREDICTION_H_

#include <iostream>
#include <vector>
#include <string>
#include "../previous_projects/dataset.h"
#include "../previous_projects/mymath.h"
#include "../previous_projects/cluster.h"
#include "coins.h"

using namespace std;

void prediction(dataset &mydata, coins &mycoins, int number_of_best);
void prediction_cluster_prepare(dataset &mydata, vector<cluster> &myclusters);

#endif