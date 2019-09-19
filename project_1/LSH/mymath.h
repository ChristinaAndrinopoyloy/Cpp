#ifndef _MYMATH_H_
#define _MYMATH_H_

#include <vector>
#include <math.h>
#include <chrono>
#include <random>
#include <numeric>
#include <algorithm>
#include <functional>
#include <iterator>
#include "dataset.h"

using namespace std;

double vector_multiplication(vector<double> vector1, vector<double> vector2);
double compute_distance(vector<double> a, vector<double> b, dataset &data);
vector<double> generate_vector_normalDistribution(int d);
float float_vector_multiplication(vector<int> vector1, vector<float> vector2, int size);

#endif