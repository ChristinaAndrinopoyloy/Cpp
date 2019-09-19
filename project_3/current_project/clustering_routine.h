#ifndef _CLUSTERING_ROUTINE_H_
#define _CLUSTERING_ROUTINE_H_

#include <iostream>
#include <vector>
#include <utility>
#include "read_data.h"
#include "../previous_projects/dataset.h"
#include "../previous_projects/initialization.h"
#include "../previous_projects/assignment.h"
#include "../previous_projects/cluster.h"
#include "../previous_projects/update.h"
#include "../previous_projects/LSH.h"
#include "../previous_projects/hypercube.h"
#include "../previous_projects/hash_helper.h"
#include "../previous_projects/evaluation.h"

#define NONE -1
#define LSH_METHOD 4
#define HYPERCUBE_METHOD 5

using namespace std;

void clustering_routine(dataset &mydata, vector<cluster> &clusters, int number_of_clusters);
void interaction_with_user(int &initialization_method, int &assign, int &assign_method, int &update_method);

#endif