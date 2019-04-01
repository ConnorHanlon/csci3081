/*
Copyright (c) 2018 Connor Hanlon
*/
#ifndef IMAGETOOLS_CONVOLUTION_FILTER_SHARPEN_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_SHARPEN_H_

#include "imagetools/convolution_filter.h"

#include <cmath>

namespace image_tools {

/** @brief "Sharpens the image in propotion to the amount specified in the GUI
 by convolving the image with an appropriate sharpening kernel." - Documentation
Description. */
class ConvolutionFilterSharpen : public ConvolutionFilter {
 public:
  /** Default sharpen filter with a radius of 1. */
  ConvolutionFilterSharpen();

  /** Constructor setting the radius to parameter radius.*/
  explicit ConvolutionFilterSharpen(float radius);

  virtual ~ConvolutionFilterSharpen();

  /** The sharpen filter creates a 3x3 kernel, normalize so all values add to
  1, set all values to -1, and set the middle value according to the radius
  value. */
  FloatMatrix *CreateKernel() override;

  /** Returns the filter's radius. */
  float radius() const { return floor(radius_); }

 private:
  float radius_;
};

}  // namespace image_tools

#endif  //  IMAGETOOLS_CONVOLUTION_FILTER_SHARPEN_H_
