/*
Copyright (c) 2018 Connor Hanlon
*/
#include "imagetools/convolution_filter_edge.h"

namespace image_tools {
  ConvolutionFilterEdge::ConvolutionFilterEdge() {}

  ConvolutionFilterEdge::~ConvolutionFilterEdge() {}

  // Kernel of size 3x3 with all values set to -1 and a center value equal to 8.
  FloatMatrix *ConvolutionFilterEdge::CreateKernel() {
    FloatMatrix *new_kernel = new FloatMatrix(1);
    new_kernel->Scale(-1);
    new_kernel->set_value(1, 1, 8);  // center is located at (1,1) with value=8
    return new_kernel;
  }
}  // namespace image_tools
