#ifndef _NEAREST_POINT_H_
#define _NEAREST_POINT_H_

#include <vector>

using namespace std;

class nearest_point
{
  private:
    int min_point;
    float distance;

  public:
    nearest_point();
    ~nearest_point();
    int get_min_point();
    void set_min_point(int set_point);
    float get_distance();
    void set_distance(float set_dist);
};

#endif