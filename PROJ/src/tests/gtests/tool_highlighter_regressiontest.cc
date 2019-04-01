/**
Copyright (c) 2018 Connor Hanlon
**/
#include "gtest/gtest.h"

#include "imagetools/tool_highlighter.h"
#include "imagetools/color_data.h"
#include "imagetools/image_editor.h"
#include "imagetools/pixel_buffer.h"

using image_tools::ToolHighlighter;
using image_tools::ColorData;
using image_tools::ImageEditor;
using image_tools::PixelBuffer;


class ToolHighlighterRegressionTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  ToolHighlighter tool_;
  const std::string input_file = "./resources/test-standard.png";
  const std::string file_truth = "./resources/tool_highlighter_truth.png";
};

TEST_F(ToolHighlighterRegressionTest, MatchesTestToolImage) {
  PixelBuffer e_buf = PixelBuffer(1280, 720, ColorData(1, 1, 1));
  PixelBuffer t_buf = PixelBuffer(1280, 720, ColorData(1, 1, 1));

  ImageEditor* e_editor = new ImageEditor(&e_buf);
  ImageEditor* t_editor = new ImageEditor(&t_buf);

  e_editor->LoadFromFile(file_truth);
  t_editor->LoadFromFile(input_file);

  // t_editor->CreateToolTruthFile(tool_.name(), input_file, file_truth);

  t_editor->StartStroke(tool_.name(), ColorData(0.5, 0.5, 0.5), 10.0, 10, 10);
  t_editor->EndStroke(10, 10);

  PixelBuffer expect = *(e_editor->pixel_buffer());
  PixelBuffer test_buf = *(t_editor->pixel_buffer());

  bool test_val = (expect == test_buf);

  delete e_editor;
  delete t_editor;
  e_editor = NULL;
  t_editor = NULL;

  EXPECT_TRUE(test_val);
}
