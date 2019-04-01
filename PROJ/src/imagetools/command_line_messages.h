/**
 Copyright (c) 2018 Connor Hanlon
*/
#ifndef IMAGETOOLS_COMMAND_LINE_MESSAGES_H_
#define IMAGETOOLS_COMMAND_LINE_MESSAGES_H_

#include <string>

namespace image_tools {

/** @brief A static class that returns command line messages **/
class CommandLineMessages {
 public:
  /** Standard usage message that lists all possible valid inputs via the
  the command line. **/
  static std::string UsageMessage() {
    std::string help =
    "\nusage: mia infile.png [image processing commands ...] outfile.png \n\n"

    "infile.png:          input image file in png format \n"
    "outfile.png:         filename to use for saving the result \n\n"

    "-blur r:             apply a gaussian blur of radius r \n"
    "-edgedetect:         apply an edge detection filter \n"
    "-sharpen r:          apply a sharpening filter of radius r \n"
    "-red s:              scale the red channel by a factor s \n"
    "-green s:            scale the green channel by a factor s \n"
    "-blue s:             scale the blue channel by a factor s \n"
    "-quantize n:         quantize each color channel into n bins \n"
    "-saturate s:         saturate colors by scale factor s \n"
    "-threshold c:        threshold using the cutoff value c \n"
    "-motionblur-n-s r:    north-south motion blur with kernel radius r \n"
    "-motionblur-e-w r:    east-west motion blur with kernel radius r \n"
    "-motionblur-ne-sw r:  ne-sw motion blur with kernel radius r \n"
    "-motionblur-nw-se r:  nw-se motion blur with kernel radius r \n";
    return help;
  }

  /** Returns the usage description of a desired command. **/
  static std::string GetUsage(std::string command) {
    std::string usage;
    if (command == "-blur") {
      usage = "apply a gaussian blur of radius r";
    } else if (command == "-edgedetect") {
      usage = "apply an edge detection filter";
    } else if (command == "-sharpen") {
      usage = "apply a sharpening filter of radius r";
    } else if (command == "-red") {
      usage = "scale the red channel by a factor s";
    } else if (command == "-green") {
      usage = "scale the green channel by a factor s";
    } else if (command == "-blue") {
      usage = "scale the blue channel by a factor s";
    } else if (command == "-quantize") {
      usage = "quantize each color channel into n bins";
    } else if (command == "-saturate") {
      usage = "saturate colors by scale factor s";
    } else if (command == "-threshold") {
      usage = "threshold using the cutoff value c";
    } else if (command == "-motionblur-n-s") {
      usage = "north-south motion blur with kernel radius r";
    } else if (command == "-motionblur-e-w") {
      usage = "east-west motion blur with kernel radius r";
    } else if (command == "-motionblur-ne-sw") {
      usage = "ne-sw motion blur with kernel radius r";
    } else {
      usage = "nw-se motion blur with kernel radius r";
    }
    return usage;
  }

  /** Returns a formatted error message to the command line user depending on The
  input error code.
  ERROR CODES:
    2: File does not exist
    3: Invalid input value
    4: Unrecognized command/incorrect
    5: Missing value for a command
    6: Invalid File
  **/
  static std::string ErrorMessage(int e) {
    std::string error_message;
    if (e == 2) {
      error_message =
      "File does not exist or extension is incorrect. \n"
      "Program exited with error code 2\n";
    } else if (e == 3) {
      error_message = "Program exited with error code 3\n";
    } else if (e == 4) {
      error_message = "Program exited with error code 4\n";
    } else if (e == 5) {
      error_message =
      "Missing value for command\n"
      "Program exited with error code 5\n";
    } else if (e == 6) {
      error_message =
      "Invalid filename error \n"
      "Program exited with error code 6\n";
    }
    return error_message;
  }

  /** Returns a specific error message depending on the command to inform the
  command line user the specific problem that caused the exception. **/
  static std::string CommandsErrorMessage(std::string command, int error) {
    std::string error_message;
    if (error == 3) {
      error_message =
      "Invalid input value for the command " + command + "\n"
      "The proper input value must be between 0 and 10.\n"
      "Command usage: " + GetUsage(command) + "\n";
    } else if (error == 4) {
      error_message = "Unrecognized command" + command + "\n"
      "please retry with the one of the following" + UsageMessage() + "\n";
    }
    return error_message;
  }
};

}  // namespace image_tools

#endif  //  IMAGETOOLS_COMMAND_LINE_MESSAGES_H_
