#include "normalization.h"

bool IsZero(double number)
{
    return (number == 0.0);
}

void normalize(dataset &mydata)
{
    double sum = 0.0;
    double norm;
    int all_zeros;

    for (int i = 0; i < mydata.get_number_of_points(); i++)
    {
        if (all_of(mydata.get_data(i).get_point().second.begin(), mydata.get_data(i).get_point().second.end(), [](double i) { return i==0.0; }))
        {
        }
        else
        {
            sum = accumulate(mydata.get_data(i).get_point().second.begin(), mydata.get_data(i).get_point().second.end(), 0.0);
            all_zeros = count_if(mydata.get_data(i).get_point().second.begin(), mydata.get_data(i).get_point().second.begin(), IsZero);
            norm = sum / (double)(mydata.get_data(i).get_point().second.size() - all_zeros);
            for (unsigned int j = 0; j < mydata.get_data(i).get_point().second.size(); j++)
            {
                mydata.get_point_to_data(i)->get_point().second[j] = mydata.get_point_to_data(i)->get_point().second[j] - norm;
            }
        }
    }
    return;
}