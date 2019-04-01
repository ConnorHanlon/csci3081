/*
Copyright (c) 2018 Connor Hanlon
*/
#include "imagetools/convolution_filter.h"

#include <stdio.h>
#include <math.h>

#include "imagetools/image_tools_math.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

ConvolutionFilter::ConvolutionFilter() {}

ConvolutionFilter::~ConvolutionFilter() {}

void ConvolutionFilter::SetUpFilter() {
  kernel_ = CreateKernel();
}

ColorData ConvolutionFilter::CalculateFilteredPixel(PixelBuffer *buffer,
                                                    int x, int y) {
  float red = 0.0;
  float green = 0.0;
  float blue = 0.0;
  int kernel_width = kernel_->width();
  int kernel_height = kernel_->height();
  /**  For every element in the kernel, calculate the intensities of each rgd
  channel by examining the neighbors of (x,y) that correspond to the position
  in the filter's kernel. */
  for (int kernel_x = 0; kernel_x < kernel_width; kernel_x++) {
    for (int kernel_y = 0; kernel_y < kernel_height; kernel_y++) {
      int buffer_x = (x - (kernel_width / 2) + kernel_x + buffer->width());
      int bounds_x = buffer_x % buffer->width();
      int buffer_y = (y - (kernel_height /2) + kernel_y + buffer->height());
      int bounds_y = buffer_y % buffer->height();
      float kernel_xy_value = kernel_->value(kernel_x, kernel_y);
      ColorData image_buffer_xy_pixel = buffer->pixel(bounds_x, bounds_y);
      red += (image_buffer_xy_pixel.red() * kernel_xy_value);
      blue += (image_buffer_xy_pixel.blue() * kernel_xy_value);
      green += (image_buffer_xy_pixel.green() * kernel_xy_value);
    }
  }
  // Clamp each rbg channel value after calculation with the kernel to a range
  // of 0 to 255.
  float min = 0.0;
  float max = 255.0;
  float final_red = ImageToolsMath::Clamp(red, min, max);
  float final_green = ImageToolsMath::Clamp(green, min, max);
  float final_blue = ImageToolsMath::Clamp(blue, min, max);
  return ColorData(final_red, final_green, final_blue);
}

void ConvolutionFilter::CleanupFilter() {
  delete kernel_;
  kernel_ = NULL;
}

}  // namespace image_tools
