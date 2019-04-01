/**
Copyright (c) 2018 Connor Hanlon
*/
#include "gtest/gtest.h"
#include "imagetools/convolution_filter_blur.h"

using image_tools::ConvolutionFilterBlur;

class ConvolutionFilterBlurTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  ConvolutionFilterBlur filter_;
};

TEST_F(ConvolutionFilterBlurTest, HasCorrectRadius) {
  EXPECT_EQ(filter_.radius(), 1.0);
}
