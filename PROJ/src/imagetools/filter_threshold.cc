/*
Copyright (c) 2018 Connor Hanlon
*/

#include "imagetools/filter_threshold.h"

namespace image_tools {

FilterThreshold::FilterThreshold() {
  cutoff_value_ = 0.5;
}

FilterThreshold::FilterThreshold(float cutoff) : cutoff_value_(cutoff) {}

FilterThreshold::~FilterThreshold() {}

ColorData FilterThreshold::CalculateFilteredPixel(PixelBuffer *buffer,
                                                  int x, int y) {
  ColorData pixel_col = buffer->pixel(x, y);
  float tot_intensity = pixel_col.red() + pixel_col.green() + pixel_col.blue();
  float average_intensity = tot_intensity / 3;
  if (average_intensity > cutoff()) {
    return ColorData(1.0, 1.0, 1.0);
  } else {
    return ColorData(0.0, 0.0, 0.0);
  }
}


}  /* namespace image_tools */
