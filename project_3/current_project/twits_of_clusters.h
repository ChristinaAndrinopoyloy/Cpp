#ifndef _TWITS_OF_CLUSTERS_H_
#define _TWITS_OF_CLUSTERS_H_

#include <iostream>
#include <vector>
#include <utility>
#include "tweets.h"
#include "../previous_projects/cluster.h"
#include "../previous_projects/dataset.h"

using namespace std;

vector<mypoint> twits_of_clusters(vector<cluster> &myclusters, twits &mytwits);

#endif
