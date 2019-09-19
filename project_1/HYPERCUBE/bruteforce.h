#ifndef _BRUTEFORCE_H_
#define _BRUTEFORCE_H_

#include <iostream>
#include "dataset.h"
#include "read_data.h"
#include "nearest_point.h"
#include "mymath.h"

using namespace std;

nearest_point bruteforce(vector<int> point, dataset &mydata);

#endif