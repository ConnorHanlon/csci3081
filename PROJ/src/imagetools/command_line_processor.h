/**
 Copyright (c) 2018 Connor Hanlon
*/
#ifndef IMAGETOOLS_COMMAND_LINE_PROCESSOR_H_
#define IMAGETOOLS_COMMAND_LINE_PROCESSOR_H_

#include <queue>
#include <string>
#include <map>

#include "imagetools/image_editor_commands.h"
#include "imagetools/image_editor.h"

namespace image_tools {

/** @brief The command line processor class parses the command line for use with
filters and classes within the image_tools namespace. **/
class CommandLineProcessor {
 public:
  CommandLineProcessor();
  virtual ~CommandLineProcessor();

  /** Parses the command line and determines whether the commands and filenames
  are all valid. Each valid command is added to a queue, and if all user inputs
  are valid, the commands are executed in the order that they are input. If an
  invalid input was found however, processing stops. Command line processing
  requires an input file that exists and has the right file extension. It also
  requires an output file to be named with the the right file extension. **/
  void ProcessCommandLine(int argc, char* argv[]);

  /** Returns an ImageEditorCommand with a desired input value. The input value
  if checked for validity first, and if not valid, error code 3 is thrown. if
  the input command does not match available ImageEditorCommand, then error
  code 4 is thrown. **/
  ImageEditorCommand* getCommand(std::string command,
                                const std::string& value);
  /** Checks whether the file has the correct .png extension. If the extension
  is incorrect or filename is less than 5, error code 6 is thrown. **/
  bool validFile(const std::string& fname);

  /** Checks whether the file actually exists. If file does not exist, error
  code 2 is thrown. **/
  bool file_exists(const std::string& fname);

  /** Checks the validity of the input value. The input value must be between
  0 and 10, and false is returned if value is outside of those bounds. If the
  value cannot be converted to a float, then error code 5 is thrown. **/
  bool valid_value(const std::string& value);

  inline ImageEditor* image_editor() const { return editor_; }

 private:
  ImageEditor* editor_;
  std::queue<ImageEditorCommand*> command_queue_;
};

}  // namespace image_tools

#endif   // IMAGETOOLS_COMMAND_LINE_PROCESSOR_H_
