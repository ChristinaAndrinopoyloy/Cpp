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

int vector_multiplication(vector<int> vector1,vector<int> vector2);
double compute_distance(vector<int> a, vector<int> b, dataset &data);
vector<float> generate_vector_normalDistribution(int d);
float float_vector_multiplication(vector<int> vector1,vector<float> vector2,int size);
int hammingDistance(string string1, string string2);

#endif