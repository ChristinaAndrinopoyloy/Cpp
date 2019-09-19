#ifndef _READ_DATA_H_
#define _READ_DATA_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include "dataset.h"

using namespace std;

void read_data(string file_to_open, dataset &data);
pair<int, vector<double>> split(string &line, char del, int &dimension);
void remove_duplicates(dataset &mydata);
void read_from_conf(string file_to_open, int &number_of_clusters, int &number_of_hashfunctions, int &number_of_hashtables);

#endif