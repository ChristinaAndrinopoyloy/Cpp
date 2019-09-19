#include <iostream>
#include <ctime>
#include <fstream>
#include "read_data.h"
#include "dataset.h"
#include "hypercube.h"
#include "edges.h"
#include "NN.h"
#include "bruteforce.h"
#include "nearest_point.h"
#include "myMap.h"

using namespace std;

myMap mymap;

int main(int argc, char const *argv[])
{
    string answer;

    do
    {
        dataset mydata, myqueries;
        vector<edge> myhypercube;
        int k;
        int R = 5;
        int M;
        int probes;
        vector<pair<float, int>> res_vec;
        nearest_point np;
        double tLSH, tTrue;
        double sum_tLSH = 0;
        double fraction;
        double max_fraction = 0;
        string path;

        if (argc == 1)
        {
            k = 3;
            M = 10;
            probes = 3;

            cout << "INPUT FILE WITH DATA: " << endl;
            cin >> path;
            read_data(path, mydata);
            cout << "INPUT FILE WITH QUERIES" << endl;
            cin >> path;
            read_data(path, myqueries);
            myqueries.set_method(mydata.get_method());
            cout << "OUTPUT FILE" << endl;
            cin >> path;
        }
        else
        {
            string str;
            path = argv[2];
            read_data(path, mydata);
            path = argv[4];
            read_data(path, myqueries);

            str = argv[6];
            k = stoi(str);
            str = argv[8];
            M = stoi(str);
            str = argv[10];
            probes = stoi(str);
            path = argv[12];
        }
        ofstream file_(path);

        srand((unsigned)time(NULL));

        myhypercube = hypercube(mydata, mydata.get_method(), k, mymap); //make the hypercube of data

        if (file_.is_open())
        {
            for (int i = 0; i < myqueries.get_number_of_points(); i++) //for each query
            {
                clock_t begin = clock();
                res_vec = NN(1, 300, M, probes, myqueries, i, myhypercube, k, mydata.get_method(), R, mymap); //check for neighboors with KNN
                clock_t end = clock();
                tLSH = (double)(end - begin) / CLOCKS_PER_SEC;
                sum_tLSH = sum_tLSH + tLSH;

                if (res_vec[0].second != 0)
                {
                    file_ << "Query" << i << endl;
                    file_ << "R-near neighbors:" << endl;
                    for (int j = 1; j < res_vec.size(); j++)
                    {
                        if (res_vec[j].second != 0)
                        {
                            file_ << res_vec[j].second << endl;
                        }
                    }
                    file_ << "Nearest neighbor: " << res_vec[0].second << endl;
                    file_ << "distanceLSH: " << res_vec[0].first << endl;
                    clock_t begin2 = clock();
                    np = bruteforce(*(myqueries.get_data(i)), mydata); //check for neighboors with bruteforce
                    clock_t end2 = clock();
                    tTrue = (double)(end2 - begin2) / CLOCKS_PER_SEC;
                    file_ << "distanceTrue: " << np.get_distance() << endl;
                    file_ << "tLSH: " << tLSH << endl;
                    file_ << "tTrue: " << tTrue << endl;
                    file_ << endl;

                    fraction = res_vec[0].first / np.get_distance();
                    if (fraction > max_fraction)
                    {
                        max_fraction = fraction;
                    }
                }
            }
            file_ << "fr = " << max_fraction << endl;
            file_ << "avg tLSH = " << sum_tLSH / myqueries.get_number_of_points() << endl;
            file_.close();
            for (unsigned int i = 0; i < mymap.size(); i++)
            {
                cout << "----------- " << mymap[i] << endl;
            }
        }
        else
        {
            cout << "ERROR at writing data." << endl;
        }

        cout << "Do you want to repeat the execution of programm?" << endl;
        cin >> answer;
    } while (answer == "Y");

    return 0;
}