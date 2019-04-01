/**
Copyright (c) 2018 Connor Hanlon
*/
#include <string>

#include "gtest/gtest.h"
#include "imagetools/color_data.h"
#include "imagetools/convolution_filter_blur.h"
#include "imagetools/image_editor.h"
#include "imagetools/pixel_buffer.h"


using image_tools::ConvolutionFilterBlur;
using image_tools::PixelBuffer;
using image_tools::ImageEditor;

class ConvolutionFilterBlurRegressionTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  ConvolutionFilterBlur filter_;
  const std::string blur5_truth = "PROJ/resources/blur5_truth.png";
  const std::string test_input = "PROJ/resources/test-standard.png";
};

TEST_F(ConvolutionFilterBlurRegressionTest, MatchesTestBlurImage) {
  PixelBuffer expect_buf = PixelBuffer(1280, 720,
                                      image_tools::ColorData(1, 1, 1));
  PixelBuffer test_buf = PixelBuffer(1280, 720,
                                      image_tools::ColorData(1, 1, 1));
  ImageEditor* e_editor = new ImageEditor(&expect_buf);
  ImageEditor* t_editor = new ImageEditor(&test_buf);

  e_editor->LoadFromFile(blur5_truth);
  t_editor->LoadFromFile(test_input);
  t_editor->ApplyBlurFilter(5.0);

  PixelBuffer expect = *(e_editor->pixel_buffer());
  PixelBuffer test = *(t_editor->pixel_buffer());

  bool t = (test == expect);
  EXPECT_TRUE(t);

  delete e_editor;
  delete t_editor;
  e_editor = NULL;
  t_editor = NULL;
}
