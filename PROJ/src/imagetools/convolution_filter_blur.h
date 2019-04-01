/*
Copyright (c) Connor Hanlon 2018
*/
#ifndef IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_

#include <cmath>
#include "imagetools/convolution_filter.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

/** Uses a Gaussian Blur image convolution kernel to blur the image in
proportion to the amount specified in the GUI." - Documentation Description. */
class ConvolutionFilterBlur : public ConvolutionFilter {
 public:
   /** @brief Default blur filter with a radius value of 1, which creates a kernel of
   size 3x3. */
  ConvolutionFilterBlur();

  explicit ConvolutionFilterBlur(float radius);

  virtual ~ConvolutionFilterBlur();

  /**  Create a kernel with the input radius size, which is a matrix with width equal
  to (2*radius) + 1 and a height (2*radius) + 1. A gaussian function is used to
  determine the values for every value in the kernel. */
  FloatMatrix *CreateKernel() override;

  // Possible bug, the radius actually doesn't return an exact radius but a
  // random float between r and r+1. Using floor to get the exact radius
  float radius() const { return floor(radius_); }

 private:
  float radius_;
};

}  //  namespace image_tools

#endif  // IMAGETOOLS_CONVOLUTION_FILTER_BLUR_H_
