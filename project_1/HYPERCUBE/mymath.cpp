#include "mymath.h"

/*vector1 * vector2 = result*/
int vector_multiplication(vector<int> vector1, vector<int> vector2)
{
    return inner_product(vector1.begin(), vector1.end(), vector2.begin(), 0);
}

/*vector1 * vector2 = result*/
float float_vector_multiplication(vector<int> vector1, vector<float> vector2, int size)
{
    return inner_product(vector1.begin(), vector1.end(), vector2.begin(), 0);
}

/* euclidean or cosine distance of two vectors*/
double compute_distance(vector<int> a, vector<int> b, dataset &data)
{
    if (data.get_method() == "euclidean")
    {
        double dist;

        vector<double> auxiliary;
        transform(a.begin(), a.end(), b.begin(), back_inserter(auxiliary),
                  [](int element1, int element2) { return pow((element1 - element2), 2); });
        auxiliary.shrink_to_fit();

        dist = sqrt(std::accumulate(auxiliary.begin(), auxiliary.end(), 0));
        return dist;
    }
    else
    {
        double num, denom;
        double norm_a = 0;
        double norm_b = 0;

        num = vector_multiplication(a, b);
        norm_a = vector_multiplication(a, a);
        norm_b = vector_multiplication(b, b);
        denom = sqrt(norm_a * norm_b);

        return 1 - num / denom;
    }
}

/*generate a v~N(0,1) vector*/
vector<float> generate_vector_normalDistribution(int d)
{
    int i;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    vector<float> vector;

    normal_distribution<float> distribution(0.0, 1.0);

    for (i = 0; i < d; i++)
    {
        vector.push_back(distribution(generator));
    }

    return vector;
}

/* compute hamming distance*/
int hammingDistance(string string1, string string2)
{
    unsigned int i;
    int count = 0;

    for (i = 0; i < string1.size(); i++)
    {
        if (string1[i] != string2[i])
            count++;
        i++;
    }
    return count;
}