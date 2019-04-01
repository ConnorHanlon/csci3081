/**
Copyright (c) 2018 Connor Hanlon
*/
// #include <stdio.h>
#include <cstdio>
#include <string>

#include "gtest/gtest.h"
#include "imagetools/command_line_processor.h"
#include "imagetools/convolution_filter_motion_blur.h"
#include "imagetools/image_editor_commands.h"

using image_tools::CommandLineProcessor;
using image_tools::ImageEditorCommand;

class CommandLineProcessorTest : public ::testing::Test {
  void SetUp() override {
    processor_ = new CommandLineProcessor();
    snprintf(path, sizeof(path), "p");
    snprintf(in, sizeof(in), "./test-standard.png");
    snprintf(out, sizeof(out), "./build/bin/valid_out.png");
  }

  void TearDown() override {
    delete processor_;
    processor_ = NULL;
  }

 protected:
  CommandLineProcessor* processor_;
  char path[2];
  char in[100];
  char out[100];
};

TEST_F(CommandLineProcessorTest, ValidBlurRetrieveTest) {
  std::string blur_string = "-blur";
  std::string const blur_val = "2.0";

  ImageEditorCommand* cmd = processor_->getCommand(blur_string, blur_val);

  EXPECT_EQ("-blur", cmd->name());
  delete cmd;
  cmd = NULL;
}

TEST_F(CommandLineProcessorTest, ValidMotionBlurRetrieveTest) {
  std::string mblur_string = "-motionblur-n-s";
  std::string const blur_val = "2.0";

  ImageEditorCommand* cmd = processor_->getCommand(mblur_string, blur_val);

  EXPECT_EQ("-motionblur", cmd->name());
  delete cmd;
  cmd = NULL;
}

TEST_F(CommandLineProcessorTest, ValidSharpenRetrieveTest) {
  std::string command = "-sharpen";
  std::string const val = "2.0";

  ImageEditorCommand* cmd = processor_->getCommand(command, val);

  EXPECT_EQ("-sharpen", cmd->name());
  delete cmd;
  cmd = NULL;
}

TEST_F(CommandLineProcessorTest, ValidChannelsRetrieveTest) {
  std::string command = "-red";
  std::string const val = "1.0";

  ImageEditorCommand* cmd = processor_->getCommand(command, val);

  EXPECT_EQ("-channels", cmd->name());
  delete cmd;
  cmd = NULL;
}

TEST_F(CommandLineProcessorTest, ValidQuantizeRetrieveTest) {
  std::string command = "-quantize";
  std::string const val = "1.0";

  ImageEditorCommand* cmd = processor_->getCommand(command, val);

  EXPECT_EQ("-quantize", cmd->name());
  delete cmd;
  cmd = NULL;
}

TEST_F(CommandLineProcessorTest, ValidSaturateRetrieveTest) {
  std::string command = "-saturate";
  std::string const val = "2.0";

  ImageEditorCommand* cmd = processor_->getCommand(command, val);

  EXPECT_EQ("-saturate", cmd->name());
  delete cmd;
  cmd = NULL;
}

TEST_F(CommandLineProcessorTest, ValidThresholdRetrieveTest) {
  std::string command = "-threshold";
  std::string const val = "0.5";

  ImageEditorCommand* cmd = processor_->getCommand(command, val);

  EXPECT_EQ("-threshold", cmd->name());
  delete cmd;
  cmd = NULL;
}

TEST_F(CommandLineProcessorTest, ValidCopyTest) {
  EXPECT_ANY_THROW(processor_->file_exists(out));

  char* arr[3] = {path, in, out};
  processor_->ProcessCommandLine(3, arr);

  EXPECT_NO_THROW(processor_->file_exists(out));
  std::remove(out);
}

TEST_F(CommandLineProcessorTest, InvalidOutputFileTest) {
  char* arr[4] = {path, path, path, path};
  EXPECT_ANY_THROW(processor_->ProcessCommandLine(4, arr));
}

TEST_F(CommandLineProcessorTest, InvalidInputFileTest) {
  char invalid[2] = {"i"};
  char* arr[3] = {path, invalid, out};
  EXPECT_ANY_THROW(processor_->ProcessCommandLine(3, arr));
}

TEST_F(CommandLineProcessorTest, IncorrectCommandTest) {
  char cmd1[5] = {"-blu"};
  char val1[2] = {"5"};
  char* arr[5] = {path, in, cmd1, val1, out};
  EXPECT_ANY_THROW(processor_->ProcessCommandLine(5, arr));
}

TEST_F(CommandLineProcessorTest, CorrectCommandTest) {
  char cmd1[6] = {"-blur"};
  char val1[2] = {"5"};
  char* arr[5] = {path, in, cmd1, val1, out};
  EXPECT_NO_THROW(processor_->ProcessCommandLine(5, arr));
  std::remove(out);
}

TEST_F(CommandLineProcessorTest, NoValueWithCommandTest) {
  char cmd1[6] = {"-blur"};
  char* arr[5] = {path, in, cmd1, out};
  EXPECT_ANY_THROW(processor_->ProcessCommandLine(5, arr));
}

TEST_F(CommandLineProcessorTest, InvalidValueCommandTest) {
  char cmd1[6] = {"-blur"};
  char val1[3] = {"11"};
  char* arr[5] = {path, in, cmd1, val1, out};
  EXPECT_ANY_THROW(processor_->ProcessCommandLine(5, arr));
}

TEST_F(CommandLineProcessorTest, ManyCommandsTest) {
  char blur[6] = {"-blur"};
  char edge[12] = {"-edgedetect"};
  char sat[10] = {"-saturate"};
  char thresh[11] = {"-threshold"};
  char sharp[9] = {"-sharpen"};
  char val1[2] = {"1"};
  char val2[4] = {"0.5"};

  char* arr[12] = {path, in, blur, val1, edge, sat, val2, thresh, val2, sharp,
                  val1, out};
  EXPECT_NO_THROW(processor_->ProcessCommandLine(12, arr));
  char* arr2[11] = {path, in, blur, val1, edge, val2, thresh, val2, sharp,
         val1, out};
  // should throw an error, int 4, unrecognized command for val2 after edge
  EXPECT_ANY_THROW(processor_->ProcessCommandLine(11, arr2));
  std::remove(out);
}
