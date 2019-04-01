//  Copyright (c) 2018 Connor Hanlon

#include "gtest/gtest.h"
#include "imagetools/filter_threshold.h"

using image_tools::FilterThreshold;

class FilterThresholdTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  FilterThreshold filter_;
};

TEST_F(FilterThresholdTest, HasCorrectCutoff) {
  EXPECT_EQ(filter_.cutoff(), 0.5);
}
