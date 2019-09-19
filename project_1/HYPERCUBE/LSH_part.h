#ifndef _LSH_PART_H_
#define _LSH_PART_H_

#include "dataset.h"
#include "mymath.h"

int generate_Euclidean_h_function(dataset& mydata,int order);
int generate_Cosine_h_function(dataset& mydata,int order);

#endif