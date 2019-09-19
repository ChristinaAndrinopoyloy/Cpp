#include "evaluation.h"

vector<double> evaluation(dataset &mydata, vector<cluster> &clusters)
{
    double distance;
    double smallest_distance = 10000;
    double sum_of_distance = 0.0;
    double sum_of_neighbor_distance = 0.0;
    double average_distance;
    double average_neighbor_distance;
    double silhouette;
    double sum_silhouette = 0.0;
    double sum_silhouette_per_cluster = 0.0;
    double average_silhouette, average_silhouette_per_cluster;
    silhouette_value temp;
    int neighbor;
    vector<int> neighboors;
    vector<double> returned_silhouettes;
    vector<double> temp_av_sil_per_cluster;

    for (unsigned int i = 0; i < clusters.size(); i++) // find nearest best cluster
    {
        for (unsigned int j = 0; j < clusters.size(); j++)
        {
            distance = compute_distance(clusters[i].get_representer().get_point().second, clusters[j].get_representer().get_point().second, mydata);
            if (distance != 0 && distance < smallest_distance)
            {
                smallest_distance = distance;
                neighbor = j;
            }
        }
        smallest_distance = 10000;
        neighboors.push_back(neighbor);
    }

    for (unsigned int i = 0; i < clusters.size(); i++)
    {
        for (int j = 0; j < clusters[i].get_number_of_points(); j++)
        {
            for (int n = 0; n < clusters[i].get_number_of_points(); n++)
            {
                sum_of_distance = sum_of_distance + compute_distance(clusters[i].get_data(j).get_point().second, clusters[i].get_data(n).get_point().second, mydata);
            }
            average_distance = sum_of_distance / (double)clusters[i].get_number_of_points(); // point's average distance of this cluster
            temp.set_average_distance_cluster(average_distance);
            sum_of_distance = 0.0;

            for (int m = 0; m < clusters[neighboors[i]].get_number_of_points(); m++)
            {
                sum_of_neighbor_distance = sum_of_neighbor_distance + compute_distance(clusters[i].get_data(j).get_point().second, clusters[neighboors[i]].get_data(m).get_point().second, mydata);
            }
            average_neighbor_distance = sum_of_neighbor_distance / (double)clusters[neighboors[i]].get_number_of_points(); // point's average distance of neighboor cluster
            temp.set_average_distance_neighbor_cluster(average_neighbor_distance);
            sum_of_neighbor_distance = 0.0;

            silhouette = (average_neighbor_distance - average_distance) / max(average_distance, average_neighbor_distance);
            sum_silhouette_per_cluster = sum_silhouette_per_cluster + silhouette;
            temp.set_value(silhouette);
            clusters[i].set_silhouette_value(temp, j);
        }
        average_silhouette_per_cluster = sum_silhouette_per_cluster / (double)clusters[i].get_number_of_points();
        sum_silhouette = sum_silhouette + average_silhouette_per_cluster;
        returned_silhouettes.push_back(average_silhouette_per_cluster);
        sum_silhouette_per_cluster = 0.0;
    }

    average_silhouette = sum_silhouette / (double)returned_silhouettes.size(); // total silhouette
    cout << "SILHOUETTE IS " << average_silhouette << endl;
    returned_silhouettes.push_back(average_silhouette);
    return returned_silhouettes;
}