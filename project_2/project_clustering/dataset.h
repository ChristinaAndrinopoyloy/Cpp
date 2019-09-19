#ifndef _DATASET_H_
#define _DATASET_H_

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class mypoint
{
private:
  pair<int, vector<double>> point;
  int checked;
  double distance;
  int ID_of_cluster;

public:
  mypoint();
  ~mypoint();
  pair<int, vector<double>> get_point();
  void set_point(pair<int, vector<double>> v);
  int get_checked();
  void set_checked(int set_ch);
  double get_distance();
  void set_distance(double dist);
  int get_ID_of_cluster();
  void set_ID_of_cluster(int ID);
};

class dataset
{
private:
  vector<mypoint> data;
  int number_of_points;
  int point_dimension;
  string method;
  bool q_info; //NN only : q_info = 0

public:
  dataset();
  ~dataset();
  int get_number_of_points();
  void set_number_of_points(int set_number);
  mypoint get_data(int order);
  mypoint *get_point_to_data(int order);
  void set_data(mypoint v);
  string get_method();
  void set_method(string set_meth);
  int get_point_dimension();
  void set_point_dimension(int set_dim);
  bool get_qinfo();
  void set_qinfo(bool setqinfo);
  void update(mypoint data_for_delete);
  void remove_pair(int order);
  void clear_dataset();
};

#endif