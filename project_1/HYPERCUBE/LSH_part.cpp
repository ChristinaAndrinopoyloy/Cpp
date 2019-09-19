#include "LSH_part.h"

/*generate an h function (Euklidean way)*/
int generate_Euclidean_h_function(dataset &mydata, int order)
{
    int w = 4;
    float t;
    vector<float> v(mydata.get_point_dimension());
    int h;

    t = rand() % 4;                                                                                               //t at [0,w)
    v = generate_vector_normalDistribution(mydata.get_point_dimension());                                         //v ~ N(0,1)
    h = (float_vector_multiplication((*mydata.get_data(order)), v, mydata.get_point_dimension()) + t) / (float)w; //let's h = (pv + t)/w

    return h;
}

/*generate an h function (Cosine way)*/
int generate_Cosine_h_function(dataset &mydata, int order)
{
    vector<float> r(mydata.get_point_dimension());

    r = generate_vector_normalDistribution(mydata.get_point_dimension());
    if (float_vector_multiplication(*(mydata.get_data(order)), r, mydata.get_point_dimension()) >= 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}