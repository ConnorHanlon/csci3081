/*
Copyright (c) 2018 Connor Hanlon
*/
#ifndef IMAGETOOLS_CONVOLUTION_FILTER_EDGE_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_EDGE_H_

#include "imagetools/convolution_filter.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

/** @brief "Transforms the image into one that only shows the edge of the shapes
by convolving it with a 3x3 edge detection kernel. Pixels on the border of
differently colored regions with be bright, while the pixels in ares of low
change with be dark." - Documentation Details. */
class ConvolutionFilterEdge : public ConvolutionFilter {
 public:
  ConvolutionFilterEdge();

  virtual ~ConvolutionFilterEdge();

  /** Creates a kernel of size 3x3 with all values set to -1 and a center value
  equal to 8. */
  FloatMatrix *CreateKernel() override;
};

}  // namespace image_tools

#endif  //  IMAGETOOLS_CONVOLUTION_FILTER_EDGE_H_
