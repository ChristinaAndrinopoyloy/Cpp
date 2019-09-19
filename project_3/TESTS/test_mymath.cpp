#include "test_mymath.h"

TEST(VectorMultiplication, Multiplication)
{
    EXPECT_NEAR(vector_multiplication({1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}), 3.0, abs(0.5));
    EXPECT_NEAR(vector_multiplication({2.32, -5.66, 4.5}, {-1.21, 2.195, -3.0}), -28.7309, abs(0.5));
    EXPECT_NEAR(vector_multiplication({1.0}, {1.0}), 1.0, abs(0.5));
}

TEST(ComputeDistance, Dist)
{
    dataset test_data;
    test_data.set_method("euclidean");
    EXPECT_NEAR(compute_distance({1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, test_data), 0.0, abs(0.5));
    EXPECT_NEAR(compute_distance({1.0, 1.0}, {0.0, 0.0, 1.0}, test_data), (double)sqrt(2), abs(0.5));
    test_data.set_method("cosine");
    EXPECT_NEAR(compute_distance({1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, test_data), 0.0, abs(0.5));
    EXPECT_NEAR(compute_distance({1.0, 1.0}, {0.0, 0.0, 1.0}, test_data), (double)sqrt(2), abs(0.5));
}

TEST(HammingDistanceTest, hammingDist)
{
    EXPECT_EQ(hammingDistance("000", "000"), 0);
    EXPECT_EQ(hammingDistance("1111", "1111"), 0);
    EXPECT_EQ(hammingDistance("1", "0"), 1);
    EXPECT_EQ(hammingDistance("101", "000"), 2);
}