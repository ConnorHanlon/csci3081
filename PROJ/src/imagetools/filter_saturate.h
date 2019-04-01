/*
Copyright (c) 2018 Connor Hanlon
*/

#ifndef IMAGETOOLS_FILTER_SATURATE_H_
#define IMAGETOOLS_FILTER_SATURATE_H_

#include "imagetools/filter.h"
#include "imagetools/color_data.h"


namespace image_tools {

/** @brief "Increases or decreases the colorfulness of the image" -
Documentation Description. */
class FilterSaturate : public Filter {
 public:
  /** Creates a base saturate filter with a scale of 1.0 */
  FilterSaturate();

  /** Creates a saturate filter with a scale of of parameter s */
  explicit FilterSaturate(float s);

  virtual ~FilterSaturate();

  /** Gets the pixel at (x,y), finds the greyscale value using luminance,
  lerps each color of the pixel, and returns a new ColorData with the
  lerped colors. */
  ColorData CalculateFilteredPixel(PixelBuffer *buffer, int x, int y) override;

  inline float scale() const { return scale_; }

 private:
  float scale_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_SATURATE_H_
