#ifndef _LSH_H_
#define _LSH_H_

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <time.h>
#include <sstream>
#include <iterator>
#include "dataset.h"
#include "read_data.h"
#include "mymath.h"
#include "hash_helper.h"
#include "NN.h"

using namespace std;

typedef unordered_multimap<string, myvalue> HashTable;

unordered_multimap<string, myvalue> LSH(dataset &mydata, string method);
vector<int> generate_g_hashfunction(dataset *mydata, int k, int order, string method);
int generate_Euclidean_h_function(dataset *mydata, int order);
int generate_Cosine_h_function(dataset *mydata, int order);

#endif