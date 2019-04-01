//  Copyright (c) 2018 Connor Hanlon

#include "gtest/gtest.h"
#include "imagetools/filter_saturate.h"

using image_tools::FilterSaturate;

class FilterSaturateTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  FilterSaturate filter_sat_;
};

TEST_F(FilterSaturateTest, HasCorrectScale) {
  EXPECT_EQ(filter_sat_.scale(), 1.0);
}
