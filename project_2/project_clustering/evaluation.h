#ifndef _EVALUATION_H_
#define _EVALUATION_H_

#include <iostream>
#include "dataset.h"
#include "cluster.h"
#include "mymath.h"

using namespace std;

vector<double> evaluation(dataset &mydata, vector<cluster> &clusters);

#endif