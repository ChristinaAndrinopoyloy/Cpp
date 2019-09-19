#ifndef _READ_ANALYZED_DATA_H_
#define _READ_ANALYZED_DATA_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include "dataset.h"

using namespace std;

void read_analyzed_data(string file_to_open, dataset &data);
pair<int, vector<double>> split_analyzed(string &line, char del, int &dimension);
//void remove_duplicates(dataset &mydata);

#endif