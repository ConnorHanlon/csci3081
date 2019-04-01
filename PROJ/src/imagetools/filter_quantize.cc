/*
Copyright (c) 2018 Connor Hanlon
*/
#include "imagetools/filter_quantize.h"

#include <math.h>

namespace image_tools {

FilterQuantize::FilterQuantize() {
  num_bins_ = 3;
}

FilterQuantize::FilterQuantize(int num) : num_bins_(num) {}

FilterQuantize::~FilterQuantize() {}

ColorData FilterQuantize::CalculateFilteredPixel(PixelBuffer *buffer,
                                                int x, int y) {
  int num_steps = num_bins() - 1;
  ColorData pixel_color = buffer->pixel(x, y);
  float red = roundf(pixel_color.red() * num_steps) / num_steps;
  float green = roundf(pixel_color.green() * num_steps) / num_steps;
  float blue = roundf(pixel_color.blue() * num_steps) / num_steps;
  return ColorData(red, green, blue);
}

}  // namespace image_tools
