/**
Copyright (c) 2018 Connor Hanlon
**/
#include <cstdio>
#include <iostream>

#include "gtest/gtest.h"
#include "imagetools/color_data.h"
#include "imagetools/image_editor.h"
#include "imagetools/pixel_buffer.h"

using image_tools::ColorData;
using image_tools::ImageEditor;
using image_tools::PixelBuffer;


class LoadSaveTest : public ::testing::Test {
  void SetUp() override {}

 protected:
  const std::string input_file = "./resources/test-standard.png";
  const std::string test_truth = "./resources/load_saved_file.png";
};

TEST_F(LoadSaveTest, SavedFileMatchesOriginal) {
  PixelBuffer buf = PixelBuffer(1280, 720, ColorData(1, 1, 1));
  ImageEditor* editor = new ImageEditor(&buf);

  editor->LoadFromFile(input_file);
  editor->SaveToFile(test_truth);

  PixelBuffer t_buf = PixelBuffer(1280, 720, ColorData(1, 1, 1));
  ImageEditor* t_editor = new ImageEditor(&t_buf);

  t_editor->LoadFromFile(test_truth);

  PixelBuffer expect = *(editor->pixel_buffer());
  PixelBuffer test_buf = *(t_editor->pixel_buffer());

  EXPECT_EQ(expect, test_buf);

  char out[100];
  snprintf(out, sizeof(out), "./resources/load_saved_file.png");
  // char out[test_truth.length()+1];
  // strcpy(out, test_truth.c_str());
  std::remove(out);

  delete editor;
  delete t_editor;
  editor = NULL;
  t_editor = NULL;
}
