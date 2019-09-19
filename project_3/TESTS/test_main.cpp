#include "gtest/gtest.h"
#include "test_mymath.h"
#include "test_sentiment_analysis.h"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
