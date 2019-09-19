#include "dataset.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*constructor - destructor*/
mypoint::mypoint(/* args */)
{
    checked = 0;
    distance = 100000;
    ID_of_cluster = -1;
}

mypoint::~mypoint()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*getters - setters*/
pair<int, vector<double>> mypoint::get_point()
{
    return point;
}

void mypoint::set_point(pair<int, vector<double>> v)
{
    point = v;
}

int mypoint::get_checked()
{
    return checked;
}

void mypoint::set_checked(int set_ch)
{
    checked = set_ch;
}

double mypoint::get_distance()
{
    return distance;
}

void mypoint::set_distance(double dist)
{
    distance = dist;
}

int mypoint::get_ID_of_cluster()
{
    return ID_of_cluster;
}

void mypoint::set_ID_of_cluster(int ID)
{
    ID_of_cluster = ID;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*constructor - destructor*/
dataset::dataset()
{
    set_method("euclidean");
    set_number_of_points(0);
    set_qinfo(1);
}

dataset::~dataset()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*getters - setters*/
int dataset::get_number_of_points()
{
    return number_of_points;
}

void dataset::set_number_of_points(int set_number)
{
    number_of_points = set_number;
}

mypoint dataset::get_data(int order)
{
    return data[order];
}

mypoint *dataset::get_point_to_data(int order)
{
    return &data[order];
}

void dataset::set_data(mypoint v)
{
    data.push_back(v);
}

string dataset::get_method()
{
    return method;
}

void dataset::set_method(string set_meth)
{
    method = set_meth;
}

int dataset::get_point_dimension()
{
    return point_dimension;
}

void dataset::set_point_dimension(int set_dim)
{
    point_dimension = set_dim;
}

bool dataset::get_qinfo()
{
    return q_info;
}

void dataset::set_qinfo(bool setqinfo)
{
    q_info = setqinfo;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*update*/
void dataset::update(mypoint data_for_delete)
{
    int times = 0;

    for (int i = 0; i < number_of_points; i++)
    {
        if (data_for_delete.get_point().first == data[i].get_point().first)
        {
            //  data.erase(data.begin() + i);
            data.at(i) = data.back();
            data.pop_back();
            times = times + 1;
        }
    }
    number_of_points = number_of_points - times;
}

void dataset::remove_pair(int order)
{
    data.at(order) = data.back();
    data.pop_back();
    number_of_points--;
}

void dataset::clear_dataset()
{
    for (int i = 0; i < number_of_points; i++)
    {
        data[i].set_ID_of_cluster(-1);
        data[i].set_distance(100000);
        data[i].set_checked(0);
    }
}