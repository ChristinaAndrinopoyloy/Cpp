#ifndef _EDGES_H_
#define _EDGES_H_

#include <vector>
#include <string>
#include "dataset.h"

using namespace std;

class edge //edges of cube
{
private:
  string id;
  vector<mypoint *> point;

public:
  edge();
  ~edge();
  string get_id();
  void set_id(string setid);
  mypoint *get_point(int order);
  void set_point(mypoint *setp);
  int get_size();
};

#endif