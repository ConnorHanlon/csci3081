/*
Copyright (c) 2018 Connor Hanlon
*/
#include <cmath>

#include "imagetools/convolution_filter_sharpen.h"

namespace image_tools {

ConvolutionFilterSharpen::ConvolutionFilterSharpen() {
  radius_ = 1.0;
}

ConvolutionFilterSharpen::ConvolutionFilterSharpen(float radius) :
                                                  radius_(radius) {}

ConvolutionFilterSharpen::~ConvolutionFilterSharpen() {}

FloatMatrix *ConvolutionFilterSharpen::CreateKernel() {
  FloatMatrix *new_kernel = new FloatMatrix(1);  // creates 3x3 kernel
  new_kernel->Scale(-1);
  float size = new_kernel->Sum();
  float center_val = (-1.0 * size) + radius();
  int center = ceil(new_kernel->width() / 2);
  new_kernel->set_value(center, center, center_val);
  return new_kernel;
}

}  // namespace image_tools
