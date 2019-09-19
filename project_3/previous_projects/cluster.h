#ifndef _CLUSTER_H_
#define _CLUSTER_H_

#include <utility>
#include <vector>
#include "dataset.h"

using namespace std;

class silhouette_value
{
private:
  double average_distance_cluster;
  double average_distance_neighbor_cluster;
  double value;

public:
  silhouette_value();
  ~silhouette_value();
  double get_average_distance_cluster();
  void set_average_distance_cluster(double setav);
  double get_average_distance_neighbor_cluster();
  void set_average_distance_neighbor_cluster(double setav);
  double get_value();
  void set_value(double setav);
};

class cluster
{
private:
  mypoint representer;
  vector<pair<mypoint, silhouette_value>> data;
  int number_of_points;
  pair<int, vector<double>> c_vector;

public:
  cluster();
  ~cluster();
  mypoint get_representer();
  void set_representer(mypoint setrepr);
  mypoint get_data(int order);
  void set_data(mypoint setdat);
  silhouette_value get_silhouette_value(int order);
  void set_silhouette_value(silhouette_value sv, int order);
  int get_number_of_points();
  void set_number_of_points(int setnum);
  vector<pair<mypoint, silhouette_value>> get_all_data();
  pair<int, vector<double>> get_c_vector();
  void set_c_vector(pair<int,vector<double>> setc);
  void update(int data_for_delete);
};

#endif