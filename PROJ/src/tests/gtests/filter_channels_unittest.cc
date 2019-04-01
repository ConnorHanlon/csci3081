/**
Copyright (c) 2018 Connor Hanlon
*/
#include "gtest/gtest.h"
#include "imagetools/filter_channels.h"

using image_tools::FilterChannels;

class FilterChannelsTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  FilterChannels filter_;
};

TEST_F(FilterChannelsTest, HasCorrectRedScale) {
  EXPECT_EQ(filter_.red_scale(), 1.0);
}

TEST_F(FilterChannelsTest, HasCorrectGreenScale) {
  EXPECT_EQ(filter_.green_scale(), 1.0);
}

TEST_F(FilterChannelsTest, HasCorrectBlueScale) {
  EXPECT_EQ(filter_.blue_scale(), 1.0);
}
