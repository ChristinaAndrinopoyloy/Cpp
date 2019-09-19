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
double vector_multiplication(vector<double> vector1, vector<double> vector2); // vector1 * vector2 = result
double compute_distance(vector<double> a, vector<double> b, dataset &data);   // euclidean or cosine distance of two vectors
vector<double> generate_vector_normalDistribution(int d);                     //generate a v~N(0,1) vector
int hammingDistance(string string1, string string2);                          // compute hamming distance

#endif