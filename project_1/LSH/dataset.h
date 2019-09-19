#ifndef _DATASET_H_
#define _DATASET_H_

#include <vector>
#include <iostream>

using namespace std;

class dataset
{
private:
  vector<vector<int>> data;
  int number_of_points;
  int point_dimension;
  string method;
  bool q_info; //NN only : q_info = 0

public:
  dataset();
  ~dataset();
  int get_number_of_points();
  void set_number_of_points(int set_number);
  vector<int> *get_data(int order);
  void set_data(vector<int> v);
  string get_method();
  void set_method(string set_meth);
  int get_point_dimension();
  void set_point_dimension(int set_dim);
  bool get_qinfo();
  void set_qinfo(bool setqinfo);
};

#endif