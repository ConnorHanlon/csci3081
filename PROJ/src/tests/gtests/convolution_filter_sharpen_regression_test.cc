/**
Copyright (c) 2018 Connor Hanlon
*/
#include <string>

#include "gtest/gtest.h"
#include "imagetools/image_editor.h"
#include "imagetools/convolution_filter_sharpen.h"
#include "imagetools/pixel_buffer.h"
#include "imagetools/color_data.h"

using image_tools::ConvolutionFilterSharpen;
using image_tools::PixelBuffer;
using image_tools::ImageEditor;

class ConvolutionFilterSharpenRegressionTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  ConvolutionFilterSharpen filter_;
  const std::string file_truth = "PROJ/resources/sharpen-1_truth.png";
  const std::string test_input = "PROJ/resources/test-standard.png";
};

TEST_F(ConvolutionFilterSharpenRegressionTest, MatchesTestSharpenImage) {
  PixelBuffer expect_buf = PixelBuffer(1280, 720,
                                     image_tools::ColorData(1, 1, 1));
  PixelBuffer test_buf = PixelBuffer(1280, 720,
                                      image_tools::ColorData(1, 1, 1));
  ImageEditor* e_editor = new ImageEditor(&expect_buf);
  ImageEditor* t_editor = new ImageEditor(&test_buf);
  e_editor->LoadFromFile(file_truth);
  t_editor->LoadFromFile(test_input);
  t_editor->ApplySharpenFilter(1.0);
  PixelBuffer expect = *(e_editor->pixel_buffer());
  PixelBuffer test = *(t_editor->pixel_buffer());
  bool t = (test == expect);
  EXPECT_TRUE(t);

  delete e_editor;
  delete t_editor;
  e_editor = NULL;
  t_editor = NULL;
}
