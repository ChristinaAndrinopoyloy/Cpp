#ifndef _INITIALIZATION_H_
#define _INITIALIZATION_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <chrono>
#include <random>
#include <numeric>
#include <algorithm>
#include <functional>
#include <iterator>
#include "dataset.h"
#include "mymath.h"

using namespace std;

dataset initialization(int method, int number_of_k_points, dataset &mydata);
double select_random_number(int myfloor, int myceil);
mypoint select_random_point(dataset mydata);

#endif