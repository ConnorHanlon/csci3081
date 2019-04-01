/**
Copyright (c) 2018 Connor Hanlon
*/
#include "gtest/gtest.h"
#include "imagetools/convolution_filter_motion_blur.h"

using image_tools::ConvolutionFilterMotionBlur;

class ConvolutionFilterMotionBlurTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  ConvolutionFilterMotionBlur filter_;
};

TEST_F(ConvolutionFilterMotionBlurTest, HasCorrectRadius) {
  EXPECT_EQ(filter_.radius(), 1.0);
}
