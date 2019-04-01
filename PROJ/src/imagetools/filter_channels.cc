/*
Copyright (c) 2018 Connor Hanlon
*/

#include "imagetools/filter_channels.h"

namespace image_tools {

FilterChannels::FilterChannels() {
  red_scale_ = 1.0;
  green_scale_ = 1.0;
  blue_scale_ = 1.0;
}

FilterChannels::FilterChannels(float r, float g, float b) :
                              red_scale_(r), green_scale_(g), blue_scale_(b) {}

FilterChannels::~FilterChannels() {}

// Calculates pixel at (x,y) by multiplying each individual color of the pixel
// by a scale value.
ColorData FilterChannels::CalculateFilteredPixel(PixelBuffer *buffer,
                                                int x, int y) {
  ColorData pixel_color =  buffer->pixel(x, y);
  float new_red = pixel_color.red() * red_scale();
  float new_green = pixel_color.green() * green_scale();
  float new_blue = pixel_color.blue() * blue_scale();
  return ColorData(new_red, new_green, new_blue);
}

}  // namespace image_tools
