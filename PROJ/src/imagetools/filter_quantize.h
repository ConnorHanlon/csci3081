/*
Copyright (c) 2018 Connor Hanlon
*/

#ifndef IMAGETOOLS_FILTER_QUANTIZE_H_
#define IMAGETOOLS_FILTER_QUANTIZE_H_

#include "imagetools/filter.h"
#include "imagetools/color_data.h"


namespace image_tools {

/** @brief "Reduces the number of colors in the image by binning. If using 4
bins, there will only be 4 possible intensity values for each color channel,
spaced evenly: 0%, 33%, 66%, 100%. Adjusts each color channel value R, G, and B
to put them into the nearest bin." - Documentation Description. */
class FilterQuantize : public Filter {
 public:
  /** Creates a base quantize filter with a number of bins value of 3. */
  FilterQuantize();

  /** Creates a quantize filter with a number of bins value of parameter num. */
  explicit FilterQuantize(int num);

  virtual ~FilterQuantize();

  /** Gets the pixel at (x,y) from the buffer, and puts each channel values into
  a bin. */
  ColorData CalculateFilteredPixel(PixelBuffer *buffer, int x, int y) override;

  inline int num_bins() const { return num_bins_; }

 private:
  int num_bins_;
};

}  // namespace image_tools

#endif  //  IMAGETOOLS_FILTER_QUANTIZE_H_
