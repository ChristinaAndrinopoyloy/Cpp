#include "dataset.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*constructor - destructor*/

dataset::dataset()
{
    //data = new vector<float>[get_number_of_points()];
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

vector<int>* dataset::get_data(int order)
{
    return &(data[order]);
}

void dataset::set_data(vector<int> v)
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