#ifndef _NEIGHBOOR_H_
#define _NEIGHBOOR_H_

#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include "../previous_projects/dataset.h"
#include "../previous_projects/LSH.h"
#include "../previous_projects/NN.h"

using namespace std;

void neighboor_routine(dataset &mydata, dataset &myquery);

#endif