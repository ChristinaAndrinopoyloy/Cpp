#include "test_sentiment_analysis.h"

TEST(Sentiment_Check, Sentiment)
{
    EXPECT_NEAR(compute_sentiment(0.0), 0.0, abs(0.5));
    EXPECT_NEAR(compute_sentiment(1.0), 0.25, abs(0.5));
    EXPECT_NEAR(compute_sentiment(100.0), 0.999, abs(0.5));
}