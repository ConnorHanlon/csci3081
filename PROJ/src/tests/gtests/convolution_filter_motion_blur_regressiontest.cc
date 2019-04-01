/**
Copyright (c) 2018 Connor Hanlon
*/
#include <string>

#include "gtest/gtest.h"
#include "imagetools/image_editor.h"
#include "imagetools/convolution_filter_motion_blur.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/color_data.h"

using image_tools::ConvolutionFilterMotionBlur;
using image_tools::PixelBuffer;
using image_tools::ImageEditor;

class ConvolutionFilterMotionBlurRegressionTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  ConvolutionFilterMotionBlur filter_;
};

TEST_F(ConvolutionFilterMotionBlurRegressionTest, MatchesTestMotionBlurImage) {
  const std::string file_truth = "PROJ/resources/blur-N-S-5_truth.png";
  const std::string test_input = "PROJ/resources/test-standard.png";

  PixelBuffer expect_buf = PixelBuffer(1280, 720,
                                     image_tools::ColorData(1, 1, 1));
  PixelBuffer test_buf = PixelBuffer(1280, 720,
                                      image_tools::ColorData(1, 1, 1));
  ImageEditor* e_editor = new ImageEditor(&expect_buf);
  ImageEditor* t_editor = new ImageEditor(&test_buf);
  e_editor->LoadFromFile(file_truth);
  t_editor->LoadFromFile(test_input);
  t_editor->ApplyMotionBlurFilter(5.0,
                                  ConvolutionFilterMotionBlur::BLUR_DIR_N_S);
  PixelBuffer expect = *(e_editor->pixel_buffer());
  PixelBuffer test = *(t_editor->pixel_buffer());
  bool t = (test == expect);
  EXPECT_TRUE(t);

  delete e_editor;
  delete t_editor;
  e_editor = NULL;
  t_editor = NULL;
}
