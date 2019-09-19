#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <string>
#include <ctime>
#include <algorithm>
#include <fstream>
#include "dataset.h"
#include "read_data.h"
#include "LSH.h"
#include "NN.h"
#include "bruteforce.h"
#include "nearest_point.h"

using namespace std;

int main(int argc, char const *argv[])
{
    string answer;

    do
    {
        int L;
        int k;
        int R = 4;
        dataset mydata, myquery;
        vector<int> mm;
        vector<int> myneighboors;
        nearest_point np;
        pair<vector<int>, pair<float, int>> result;
        vector<pair<float, int>> res_vec;
        string path;
        int i;
        double tLSH, tTrue;
        double sum_tLSH = 0;
        double fraction;
        double max_fraction = 0;
        clock_t begin, end, begin2, end2;

        if (argc == 1)
        {
            k = 4;
            L = 5;

            cout << "INPUT FILE WITH DATA: " << endl;
            cin >> path;
            read_data(path, mydata);
            cout << "INPUT FILE WITH QUERIES" << endl;
            cin >> path;
            read_data(path, myquery);
            cout << "OUTPUT FILE:" << endl;
            cin >> path;
        }
        else
        {
            string str;
            path = argv[2];
            read_data(path, mydata);
            path = argv[4];
            read_data(path, myquery);

            str = argv[6];
            k = stoi(str);
            str = argv[8];
            L = stoi(str);
            path = argv[10];
        }
        ofstream file_(path);
        vector<HashTable> hashtable(L);

        srand((unsigned)time(NULL));
        myquery.set_method(mydata.get_method());

        for (i = 0; i < L; i++) //make L hashtables
        {
            hashtable[i] = LSH(mydata, mydata.get_method());
        }
        if (file_.is_open())
        {
            for (int i = 0; i < myquery.get_number_of_points(); i++) //for each query
            {
                begin = clock();
                res_vec = NN(1, 300, L, hashtable, myquery, i, k, R); //check for neighboors with KNN
                end = clock();
                tLSH = (double)(end - begin) / CLOCKS_PER_SEC;
                sum_tLSH = sum_tLSH + tLSH;

                if (res_vec[0].second != 0)
                {
                    file_ << "Query" << i << endl;
                    file_ << "R-near neighbors:" << endl;
                    for (unsigned int j = 1; j < res_vec.size(); j++)
                    {
                        if (res_vec[j].second != 0)
                        {
                            file_ << res_vec[j].second << endl;
                        }
                    }
                    file_ << "Nearest neighbor: " << res_vec[0].second << endl;
                    file_ << "distanceLSH: " << res_vec[0].first << endl;
                    begin2 = clock();
                    np = bruteforce(*(myquery.get_data(i)), mydata); //check for neighboors with bruteforce
                    end2 = clock();
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
            file_ << "avg tLSH = " << sum_tLSH / myquery.get_number_of_points() << endl;
            file_.close();
        }

        cout << "Do you want to repeat the execution of programm?" << endl;
        cin >> answer;
    } while (answer == "Y");

    return 0;
}
