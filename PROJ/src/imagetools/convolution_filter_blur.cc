/*
Copyright (c) 2018 Connor Hanlon
*/
#include <cmath>
#include "imagetools/convolution_filter_blur.h"
#include "imagetools/image_tools_math.h"

namespace image_tools {

ConvolutionFilterBlur::ConvolutionFilterBlur() {
  radius_ = 1.0;
}

ConvolutionFilterBlur::ConvolutionFilterBlur(float radius) : radius_(radius) {}

ConvolutionFilterBlur::~ConvolutionFilterBlur() {}

/**  Create a kernel with the input radius size, which is a matrix with width equal
to (2*radius) + 1 and a height (2*radius) + 1. A gaussian function is used to
determine the values for every value in the kernel. */
FloatMatrix *ConvolutionFilterBlur::CreateKernel() {
    FloatMatrix *new_kernel = new FloatMatrix(radius());
    new_kernel->Scale(0);
    float center = ceil(new_kernel->width() / 2);
    for (int w = 0; w < new_kernel->width(); w++) {
      for (int h = 0; h < new_kernel->height(); h++) {
        float distance = sqrt(pow((w-radius()), 2) + pow((h-radius()), 2));
        // the pre_gaussian is the standard deviation, and the gaussian value is
        // is fully calculated by dividing the pre_gaussian by (2 * radius^2) */
        float pre_gaussian = ImageToolsMath::Gaussian(distance, center);
        float gaussian = pre_gaussian / (2 * pow(radius(), 2));
        new_kernel->set_value(w, h, gaussian);
      }
    }
    new_kernel->Normalize();
    return new_kernel;
}

}  //  namespace image_tools
