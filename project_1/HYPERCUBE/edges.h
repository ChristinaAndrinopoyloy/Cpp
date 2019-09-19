#ifndef _EDGES_H_
#define _EDGES_H_

#include <vector>
#include <string>

using namespace std;

class edge //edges of cube
{
private:
  string id;
  vector<pair<int, vector<int> *>> point;

public:
  edge();
  ~edge();
  string get_id();
  void set_id(string setid);
  pair<int, vector<int> *> get_point(int order);
  void set_point(pair<int, vector<int> *> setp);
  int get_size();
};

#endif