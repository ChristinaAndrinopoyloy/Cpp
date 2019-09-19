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
    pair<int, vector<double>> v;
    mypoint temp;

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
            v = split(line, ',', dimension);
            temp.set_point(v);
            data.set_data(temp);
            number_of_points++;
        }

        while (getline(file, line))
        {
            dimension = 0;
            v = split(line, ',', dimension);
            temp.set_point(v);
            data.set_data(temp);
            number_of_points++;
        }

        data.set_point_dimension(dimension - 1);
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
pair<int, vector<double>> split(string &line, char del, int &dimension)
{
    vector<double> v;
    int id;
    string token;
    istringstream tokenStream(line);

    while (getline(tokenStream, token, del))
    {
        if (dimension != 0)
        {
            v.push_back(atof(token.c_str()));
        }
        else
        {
            id = atof(token.c_str());
        }
        dimension++;
    }

    return make_pair(id, v);
}

void remove_duplicates(dataset &mydata)
{
    for (int j = 0; j < mydata.get_number_of_points(); j++)
    {
        for (int i = j + 1; i < mydata.get_number_of_points(); i++)
        {
            if (mydata.get_data(j).get_point().second == mydata.get_data(i).get_point().second)
            {
                mydata.remove_pair(i);
                i = j;
            }
        }
    }
}

/*open file, read file and make a dataset*/
void read_from_conf(string file_to_open, int &number_of_clusters, int &number_of_hashfunctions, int &number_of_hashtables)
{
    ifstream file;
    string value;
    vector<int> lines_from_conf;

    file.open(file_to_open);
    if (file.is_open())
    {
        while (getline(file, value))
        {
            lines_from_conf.push_back(stoi(value.substr(value.find(":") + 1)));
        }
    }
    else
    {
        cout << "The .conf file NOT FOUND!" << endl;
        return;
    }
    file.close();

    number_of_clusters = lines_from_conf[0];
    number_of_hashfunctions = lines_from_conf[1];
    number_of_hashtables = lines_from_conf[2];
    
    return;
}