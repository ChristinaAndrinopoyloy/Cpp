#include "cluster.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*constructor - destructor*/
silhouette_value::silhouette_value()
{
    average_distance_cluster = 0;
    average_distance_neighbor_cluster = 0;
    value = 100000;
}

silhouette_value::~silhouette_value()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*getters - setters*/

double silhouette_value::get_average_distance_cluster()
{
    return average_distance_cluster;
}

void silhouette_value::set_average_distance_cluster(double setav)
{
    average_distance_cluster = setav;
}

double silhouette_value::get_average_distance_neighbor_cluster()
{
    return average_distance_neighbor_cluster;
}

void silhouette_value::set_average_distance_neighbor_cluster(double setav)
{
    average_distance_neighbor_cluster = setav;
}

double silhouette_value::get_value()
{
    return value;
}

void silhouette_value::set_value(double setv)
{
    value = setv;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*constructor - destructor*/
cluster::cluster()
{
    number_of_points = 0;
}

cluster::~cluster()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*getters - setters*/
mypoint cluster::get_representer()
{
    return representer;
}

void cluster::set_representer(mypoint setrepr)
{
    representer = setrepr;
}

mypoint cluster::get_data(int order)
{
    return data[order].first;
}

void cluster::set_data(mypoint setdat)
{
    silhouette_value empty_silhouette;
    data.push_back(make_pair(setdat, empty_silhouette));
}

silhouette_value cluster::get_silhouette_value(int order)
{
    return data[order].second;
}

void cluster::set_silhouette_value(silhouette_value sv, int order)
{
    data[order].second = sv;
}

int cluster::get_number_of_points()
{
    return number_of_points;
}

void cluster::set_number_of_points(int setnum)
{
    number_of_points = setnum;
}

vector<pair<mypoint, silhouette_value>> cluster::get_all_data()
{
    return data;
}

pair<int,vector<double>> cluster::get_c_vector()
{
    return c_vector;
}

void cluster::set_c_vector(pair<int,vector<double>> setc)
{
    c_vector = setc;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*update*/
void cluster::update(int data_for_delete)
{
    int times = 0;

    for (int i = 0; i < number_of_points; i++)
    {
        if (data_for_delete == data[i].first.get_point().first)
        {
            data.erase(data.begin() + i);
            times = times + 1;
        }
    }
    number_of_points = number_of_points - times;
}