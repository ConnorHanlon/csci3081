/*
Copyright (c) 2018 Connor Hanlon
*/

#ifndef IMAGETOOLS_CONVOLUTION_FILTER_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_H_

#include "imagetools/filter.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

/** @brief Convolution filters require calculations using neighboring pixels,
meaning they cannot be calculated in place and must work on a copy image to make
sure the filter is applied correctly. Every convolution filter has a kernel
that is created that is the main function that determines a pixel's new color
based on its neighbors. */
class ConvolutionFilter : public Filter {
 public:
  ConvolutionFilter();

  virtual ~ConvolutionFilter();

  /** Subclasses must fill in this factory method to define the kernel for the
  specific filter they implement. Must be an odd dimensioned matrix, ie 3x3,
  5x5, 7x7, etc. */
  virtual FloatMatrix *CreateKernel() = 0;  // must be implemented by subclasses

  /** Overrides the Filter implementation, this function is where the kernel
  is created. */
  void SetUpFilter() override;

  /** The Filter class calls this function, which applies each sublass kernel
  to the pixel at (x,y) in the buffer. The new color calculated is returned. */
  ColorData CalculateFilteredPixel(PixelBuffer *buffer, int x, int y) override;

  /** Deletes the kernel setup by the SetUpFilter function. This is called upon
  completion of the filter. */
  void CleanupFilter() override;

  /** Overrides Filter function in order to create a copy_buffer, and allow the
  filter to be applied without disturbing the original image before all pixels
  are filtered. */
  bool can_calculate_in_place() override { return false; }

  /** Returns the filter's kernel. */
  inline FloatMatrix* kernel() const { return kernel_; }

 private:
  FloatMatrix *kernel_;
};

}  // namespace image_tools

#endif  //  IMAGETOOLS_CONVOLUTION_FILTER_H_
