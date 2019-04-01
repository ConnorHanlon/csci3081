/*
Copyright (c) 2018 Connor Hanlon
*/
#ifndef IMAGETOOLS_FILTER_THRESHOLD_H_
#define IMAGETOOLS_FILTER_THRESHOLD_H_

#include "imagetools/filter.h"
#include "imagetools/color_data.h"

namespace image_tools {

/** @brief "Each of the color channels will be rounded up to the maximum value
of 1.0 or down to the minimum value of 0.0 based on whether the pixel's value is
greater than or less than the GUI input value, respectively." - Documentation
Description. */
class FilterThreshold : public Filter {
 public:
  /** Creates a base threshold filter with a cutoff value of 0.5. */
  FilterThreshold();

  /** Creates a threshold filter with a cutoff value of parameter cutoff*/
  explicit FilterThreshold(float cutoff);

  virtual ~FilterThreshold();

  /** Get pixel from buffer at (x,y), add their intensity together to get total
  intensity. Average the total_intensity and if the average is less than the
  cutoff value, return a black pixel. Otherwise return a white pixel. */
  ColorData CalculateFilteredPixel(PixelBuffer *buffer, int x, int y) override;

  inline float cutoff() const { return cutoff_value_; }

 private:
  float cutoff_value_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_THRESHOLD_H_
