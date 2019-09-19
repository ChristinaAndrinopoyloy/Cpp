#include "update.h"

void update(int method_of_update, vector<cluster> &clusters, dataset &mydata, dataset &centroids, int &virtual_ID)
{
    vector<double> current_point(centroids.get_point_dimension());
    double cost_of_cluster = 0.0;
    vector<pair<mypoint, double>> clusters_and_costs;
    switch (method_of_update)
    {
    case 6: // K-means update
        for (unsigned int i = 0; i < clusters.size(); i++)
        {
            vector<double> mean_point(centroids.get_point_dimension(), 0.0);
            for (int j = 0; j < clusters[i].get_number_of_points(); j++)
            {
                current_point = clusters[i].get_data(j).get_point().second;
                mean_point.resize(current_point.size());
                std::transform(current_point.begin(), current_point.end(), mean_point.begin(), mean_point.begin(),
                               plus<double>());
            }
            vector<double>::iterator it = mean_point.begin();
            for (; it != mean_point.end(); ++it)
            {
                *it = *it / (double)clusters[i].get_number_of_points(); // new centroid of cluster
            }
            centroids.get_point_to_data(i)->set_point(make_pair(virtual_ID, mean_point));
            virtual_ID++;
        }
        break;
    case 7:                                                // PAM
        for (unsigned int i = 0; i < clusters.size(); i++) // for each cluster
        {
            for (int j = 0; j < clusters[i].get_number_of_points(); j++) // for each point of cluster
            {
                for (int n = 0; n < clusters[i].get_number_of_points(); n++)
                {
                    cost_of_cluster = cost_of_cluster + compute_distance(clusters[i].get_data(j).get_point().second, clusters[i].get_data(n).get_point().second, centroids);
                }
                clusters_and_costs.push_back(make_pair(clusters[i].get_data(j), cost_of_cluster));
                cost_of_cluster = 0.0;
            }
            sort(clusters_and_costs.begin(), clusters_and_costs.end(), sort_by_distance);
            centroids.get_point_to_data(i)->set_point(make_pair(clusters_and_costs[0].first.get_point().first, clusters_and_costs[0].first.get_point().second));
            clusters_and_costs.clear();
        }

        break;
    default:
        cout << "ERROR at update method!" << endl;
        break;
    }

    return;
}

bool sort_by_distance(pair<mypoint, double> &p1, pair<mypoint, double> &p2)
{
    return (p1.second < p2.second);
}
