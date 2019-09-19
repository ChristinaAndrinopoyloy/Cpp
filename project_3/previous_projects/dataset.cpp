#include "dataset.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*constructor - destructor*/
mypoint::mypoint(/* args */)
{
    checked = 0;
    distance = 100000;
    ID_of_cluster = -1;
    vector<bool> temp(100, false);
    is_mentioned = temp;
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

vector<bool> mypoint::get_is_mentioned()
{
    return is_mentioned;
}

void mypoint::set_is_mentioned(vector<bool> setv)
{
    is_mentioned = setv;
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

vector<pair<double, mypoint>> mypoint::get_myneighboors()
{
    return myneighboors;
}

pair<double, mypoint> mypoint::get_myneighboor(int order)
{
    return myneighboors[order];
}

void mypoint::set_myneighboors(vector<pair<double, mypoint>> set_v)
{
    myneighboors= set_v;
}

vector<double> mypoint::get_recommendation()
{
    return recommendation;
}

void mypoint::set_recommendation(vector<double> set_r)
{
    recommendation = set_r;
}

vector<string> mypoint::get_best_cryptos()
{
    return best_cryptos;
}

void mypoint::set_best_cryptos(string set_best)
{
    best_cryptos.push_back(set_best);
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

vector<mypoint> dataset::gg()
{
    return data;
}
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