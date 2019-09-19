#ifndef _NN_H_
#define _NN_H_

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <sstream>
#include <limits>
#include <algorithm>
#include "dataset.h"
#include "LSH.h"
#include "mymath.h"
#include "hash_helper.h"

using namespace std;

typedef unordered_multimap<string, myvalue> HashTable;

vector<pair<double, int>> NN(int r, int c, int L, vector<HashTable> hashtable, dataset myquery, int order, int k, int R);

#endif