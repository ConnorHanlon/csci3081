/**
Copyright (c) 2018 Connor Hanlon
*/
#include "gtest/gtest.h"
#include "imagetools/filter_quantize.h"

using image_tools::FilterQuantize;

class FilterQuantizeTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  FilterQuantize filter_;
};

TEST_F(FilterQuantizeTest, HasCorrectBinNumber) {
  EXPECT_EQ(filter_.num_bins(), 3);
}
