#include "read_data.h"

/*open file, read file and make a dataset*/
void read_data(string file_to_open, dataset &data)
{
    ifstream file;
    string line, method;
    string euclidean = "euclidean";
    string cosine = "cosine";
    string nearest_n = "R=0";
    int number_of_points = 0;
    int dimension;
    vector<int> v;

    method.clear();
    file.open(file_to_open);

    if (file.is_open())
    {
        getline(file, line);
        method = line;

        if (method.find(euclidean) != string::npos)
        {
            method.erase(method.end() - 1);
            data.set_method(method);
        }
        else if (method.find(cosine) != string::npos)
        {
            method.erase(method.end() - 1);
            data.set_method(method);
        }
        else if (method.find(nearest_n) != string::npos)
        {
            data.set_qinfo(0);
        }
        else
        {
            dimension = 0;
            v = split(line, ' ', dimension);
            data.set_data(v);
            number_of_points++;
        }

        while (getline(file, line))
        {
            dimension = 0;
            v = split(line, ' ', dimension);
            data.set_data(v);
            number_of_points++;
        }

        data.set_point_dimension(dimension);
        data.set_number_of_points(number_of_points);
    }
    else
    {
        cout << "The .txt file NOT FOUND!" << endl;
        return;
    }

    file.close();

    return;
}

/*from file's line to vector by spliting*/
vector<int> split(string &line, char del, int &dimension)
{
    vector<int> v;
    string token;
    istringstream tokenStream(line);

    while (getline(tokenStream, token, del))
    {
        dimension++;
        v.push_back(atof(token.c_str()));
    }

    return v;
}