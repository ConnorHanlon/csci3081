/*
Copyright (c) 2018 Connor Hanlon
*/

#ifndef IMAGETOOLS_FILTER_CHANNELS_H_
#define IMAGETOOLS_FILTER_CHANNELS_H_

#include "imagetools/filter.h"
#include "imagetools/color_data.h"

namespace image_tools {

/**  @brief "Independently scales up or down the intesity of each color channel
(red, green, and blue)." - Documentation Description. */
class FilterChannels : public Filter {
 public:
   /** Creates a base channel filter, with red, green, and blue scales set to
   a value of 1.0, which does not change the intensities of the original color
   when applied. */
  FilterChannels();

  /** Creates a channel filter and sets the rgb scales to the input params. */
  FilterChannels(float r, float g, float b);

  virtual ~FilterChannels();

  /** Calculates pixel at (x,y) by multiplying each individual color of the pixel
   by a scale value. */
  ColorData CalculateFilteredPixel(PixelBuffer *buffer, int x, int y) override;

  // returns the scale value for the red channel
  inline float red_scale() const { return red_scale_; }

  // returns the scale value for the green channel
  inline float green_scale() const { return green_scale_; }

  // returns the scale value for the blue channel
  inline float blue_scale() const { return blue_scale_; }

 private:
  float red_scale_;
  float green_scale_;
  float blue_scale_;
};

}  // namespace image_tools

#endif  // IMAGETOOLS_FILTER_CHANNELS_H_
