#ifndef _READ_DATA_H_
#define _READ_DATA_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "dataset.h"

using namespace std;

void read_data(string file_to_open, dataset &data);
vector<int> split(string &line, char del, int &dimension);

#endif