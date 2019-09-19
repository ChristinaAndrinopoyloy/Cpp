#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "./previous_projects/dataset.h"
#include "./current_project/read_data.h"
#include "./current_project/tweets.h"
#include "./current_project/sentiment_analysis.h"
#include "./current_project/coins.h"
#include "./current_project/preprocessing.h"
#include "./current_project/clustering_routine.h"
#include "./current_project/neighboor.h"
#include "./current_project/prediction.h"
#include "./previous_projects/cluster.h"
#include "./previous_projects/read_analyzed_data.h"
#include "./current_project/twits_of_clusters.h"

using namespace std;

int main(int argc, char const *argv[])
{
    lexicon mylexicon;
    coins mycoins;
    twits mytwits;
    dataset mydata, mydata2, virtual_users;
    vector<cluster> myclusters, myclusters2, myclusters3;
    string path;
    vector<mypoint> new_users;
    int number_of_new_users = 0;

    mylexicon.build_sentiment_lexicon("vader_lexicon.csv");
    mycoins.build_coin_lexicon("coins_queries.csv");
    if (argc == 1)
    {
        cout << "INPUT FILE WITH DATA: " << endl;
        cin >> path;
        read_data(path, mytwits, mylexicon, mycoins);
        cout << "OUTPUT FILE:" << endl;
        cin >> path;
    }
    else
    {
        path = argv[2];
        read_data("tweets_dataset_small.csv", mytwits, mylexicon, mycoins);
        path = argv[4];
    }
    sentiment_analysis(mytwits);
    preprocess(mytwits, mydata);
    neighboor_routine(mydata, mydata);
    //clustering_routine(mydata, myclusters, 5);
    //prediction_cluster_prepare(mydata, myclusters);
    prediction(mydata, mycoins, 5);

    read_analyzed_data("small.csv", mydata2);
    clustering_routine(mydata2, myclusters2, 5);
    new_users = twits_of_clusters(myclusters2, mytwits);

    for (unsigned int i = 0; i < new_users.size(); i++)
    {
        virtual_users.set_data(new_users[i]);
        number_of_new_users++;
    }
    virtual_users.set_method("cosine");
    virtual_users.set_number_of_points(number_of_new_users);
    virtual_users.set_point_dimension(100);

    neighboor_routine(virtual_users, mydata);
    //clustering_routine(virtual_users, myclusters3, 2);
    //prediction_cluster_prepare(mydata, myclusters3);
    prediction(mydata, mycoins, 2);

    ofstream file_(path);
    if (file_.is_open())
    {
        file_ << "LSH" << endl;
        for (int i = 0; i < mydata.get_number_of_points(); i++)
        {
            file_ << "<u" << i << ">"
                  << " ";
            for (unsigned int j = 0; j < mydata.get_point_to_data(i)->get_best_cryptos().size(); j++)
            {
                file_ << mydata.get_point_to_data(i)->get_best_cryptos()[j] << " ";
            }
            file_ << endl;
        }
        file_.close();
    }
    return 0;
}
