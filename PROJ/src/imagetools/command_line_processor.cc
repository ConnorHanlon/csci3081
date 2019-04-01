/**
Copyright (c) 2018 Connor Hanlon
*/

/**
ERROR CODES:
  2: invalid filename
  3: invalid value
  4: invalid command/unrecognized command
  5: invalid stroke command
**/

#include "imagetools/command_line_processor.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <map>

#include "imagetools/color_data.h"
#include "imagetools/command_line_messages.h"
#include "imagetools/convolution_filter_motion_blur.h"
#include "imagetools/image_editor_commands.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {
CommandLineProcessor::CommandLineProcessor() {
  editor_ = new ImageEditor();
  PixelBuffer *buf = new PixelBuffer(1280, 720,
                                     image_tools::ColorData(1, 1, 1));
  editor_->set_pixel_buffer(buf);
}

CommandLineProcessor::~CommandLineProcessor() {
  delete editor_;
  editor_ = NULL;
}


void CommandLineProcessor::ProcessCommandLine(int argc, char* argv[]) {
  if (argc <= 2) {
    std::cout << CommandLineMessages::UsageMessage() << std::endl;
  } else if (argc == 3) {
    if (file_exists(argv[1]) && validFile(argv[1]) && validFile(argv[argc-1])) {
      LoadCommand(editor_, argv[1]).Execute();
      SaveCommand(editor_, argv[2]).Execute();
    }
  } else if ((argc > 3) && validFile(argv[1]) && validFile(argv[argc-1])) {
    ImageEditorCommand* cmd = new LoadCommand(editor_, argv[1]);
    command_queue_.push(cmd);
    int cur_arg = 2;
    bool canContinue = true;
    while (cur_arg < (argc-1) && canContinue) {
      std::string com_str(argv[cur_arg]);
      if (com_str == "-h") {
        std::cout << CommandLineMessages::UsageMessage() << std::endl;
        canContinue = false;
      } else if (com_str == "-edgedetect") {
        cmd = new EdgeFilterCommand(editor_);
        command_queue_.push(cmd);
        cur_arg++;
      } else {
        try {
          cmd = getCommand(com_str, argv[cur_arg + 1]);
          command_queue_.push(cmd);
          cur_arg = cur_arg + 2;
        } catch (int e) {
          std::string er(CommandLineMessages::CommandsErrorMessage(com_str, e));
          std::cout << er << std::endl;
          canContinue = false;
          throw e;  // To be handled by the main file.
        }
      }
    }
    while (!command_queue_.empty()) {
      cmd = command_queue_.front();
      command_queue_.pop();
      cmd->Execute();
      delete cmd;
      cmd = NULL;
    }
    SaveCommand(editor_, argv[argc - 1]).Execute();
  }
}


ImageEditorCommand* CommandLineProcessor::getCommand(std::string command,
                                                     const std::string& value) {
  if (!valid_value(value)) {
    throw 3;
  }
  ImageEditorCommand* cmd;
  float val = stof(value);
  if (command == "-blur") {
    cmd = new BlurFilterCommand(editor_, val);
  } else if (command == "-sharpen") {
    cmd = new SharpenFilterCommand(editor_, val);
  } else if (command == "-red") {
    cmd = new ChannelsFilterCommand(editor_, val, 1.0, 1.0);
  } else if (command == "-green") {
    cmd = new ChannelsFilterCommand(editor_, 1.0, val, 1.0);
  } else if (command == "-blue") {
    cmd = new ChannelsFilterCommand(editor_, 1.0, 1.0, val);
  } else if (command == "-quantize") {
    cmd = new QuantizeFilterCommand(editor_, val);
  } else if (command == "-saturate") {
    cmd = new SaturateFilterCommand(editor_, val);
  } else if (command == "-threshold") {
    cmd = new ThresholdFilterCommand(editor_, val);
  } else if (command == "-motionblur-n-s") {
    cmd = new MotionBlurFilterCommand(editor_, val,
                                     ConvolutionFilterMotionBlur::BLUR_DIR_N_S);
  } else if (command == "-motionblur-e-w") {
    cmd = new MotionBlurFilterCommand(editor_, val,
                                     ConvolutionFilterMotionBlur::BLUR_DIR_E_W);
  } else if (command == "-motionblur-ne-sw") {
    cmd = new MotionBlurFilterCommand(editor_, val,
                                   ConvolutionFilterMotionBlur::BLUR_DIR_NE_SW);
  } else if (command == "-motionblur-nw-se") {
    cmd = new MotionBlurFilterCommand(editor_, val,
                                   ConvolutionFilterMotionBlur::BLUR_DIR_NW_SE);
  } else {
    throw 4;
  }
  return cmd;
}

// Determines if file is valid.
bool CommandLineProcessor::validFile(const std::string& fname) {
  // first check is an edge case, if less than 5 or greater than 100 then the
  // extension check below would throw an exception when trying to access
  // substring.
  int len = fname.length();
  if ((len < 5) || (len > 100)) {
    throw 6;
  }
  // get the last 4 characters to determine if .png
  std::string extension = fname.substr((len - 4), (len - 1));
  if (extension != ".png") {
    throw 6;
  }
  return true;
}

bool CommandLineProcessor::file_exists(const std::string& fname) {
  std::fstream ifile(fname.c_str());
  bool exists = static_cast<bool>(ifile);
  if (exists == false) {
    throw 2;
  } else {
    return true;
  }
}

// if value is not between 0 and 10, returns false
bool CommandLineProcessor::valid_value(const std::string& value) {
  float f_val;
  try {
    f_val = stof(value);
  } catch (...) {
    throw 5;
  }
  if ((f_val < 0.0) || (f_val > 10.0)) {
    return false;
  }
  return true;
}

}  // namespace image_tools
