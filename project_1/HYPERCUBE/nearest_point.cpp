#include "nearest_point.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*constructor - destructor*/

nearest_point::nearest_point()
{
}

nearest_point::~nearest_point()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*getters - setters*/

int nearest_point::get_min_point()
{
    return min_point;
}

void nearest_point::set_min_point(int set_point)
{
    min_point = set_point;
}

float nearest_point::get_distance()
{
    return distance;
}

void nearest_point::set_distance(float set_dist)
{
    distance = set_dist;
}