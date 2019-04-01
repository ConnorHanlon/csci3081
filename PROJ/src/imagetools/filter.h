/*
Copyright (c) 2018 Connor Hanlon
*/

#ifndef IMAGETOOLS_FILTER_H_
#define IMAGETOOLS_FILTER_H_

#include "imagetools/color_data.h"
#include "imagetools/pixel_buffer.h"

namespace image_tools {

class Filter {
 public:
  /** @brief The base class for filtering an image. Every filter must calculate
  a new color for each pixel in the image. The method of calculation varies. */
  Filter();
  virtual ~Filter();

  /** Applies a filter to the input buffer. */
  void ApplyToBuffer(PixelBuffer *buffer);

  /** Meant to be overriden, this method sets up the filter before use. called
  by the ApplyToBuffer function. */
  virtual void SetUpFilter();

  /** For every pixel in the image(buffer), the pixel color is calculated.
  This function does not modify the buffer, it simply returns a new ColorData
  instance. */
  virtual ColorData CalculateFilteredPixel(PixelBuffer *buffer,
                                           int x, int y) = 0;

  /** Called by the ApplyToBuffer function. */
  virtual void CleanupFilter();

  /** If a filter cannot be calculated in place, a copy buffer must be created
  and used in order to maintain integrity of filter calculations. */
  virtual bool can_calculate_in_place() { return true; }
};

}  // namespace image_tools

#endif  //  IMAGETOOLS_FILTER_H_
