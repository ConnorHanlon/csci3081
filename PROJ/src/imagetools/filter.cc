/*
Copyright (c) 2018 Connor Hanlon
*/
#include "imagetools/filter.h"

#include <stdio.h>
#include <iostream>

#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {
  Filter::Filter() {}  // how do I want this set up?
  Filter::~Filter() {}


  void Filter::ApplyToBuffer(PixelBuffer *buffer) {
    SetUpFilter();
    // if can_calculate_in_place, no need to create a copy_buffer
    if (can_calculate_in_place()) {
      for (int w = 0; w < buffer->width(); w++) {
        for (int h = 0; h < buffer->height(); h++) {
          ColorData changed_pixel = CalculateFilteredPixel(buffer, w, h);
          buffer->set_pixel(w, h, changed_pixel);
        }
      }
    // If cannot calculate in place, must create a copy_buffer.
    } else {
      PixelBuffer *copy_buffer = new PixelBuffer(*buffer);
      for (int w = 0; w < buffer->width(); w++) {
        for (int h = 0; h < buffer->height(); h++) {
          ColorData changed_pixel = CalculateFilteredPixel(copy_buffer, w, h);
          buffer->set_pixel(w, h, changed_pixel);
        }
      }
      delete copy_buffer;
      copy_buffer = NULL;
    }
    CleanupFilter();
  }

  void Filter::SetUpFilter() {}

  void Filter::CleanupFilter() {}

}  /* namespace image_tools */
