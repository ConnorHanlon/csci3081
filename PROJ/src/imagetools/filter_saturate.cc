/*
Copyright (c) 2018 Connor Hanlon
*/

#include "imagetools/filter_saturate.h"

#include "imagetools/image_tools_math.h"

namespace image_tools {

FilterSaturate::FilterSaturate() {
  scale_ = 1.0;
}

FilterSaturate::FilterSaturate(float s) : scale_(s) {}

FilterSaturate::~FilterSaturate() {}

ColorData FilterSaturate::CalculateFilteredPixel(PixelBuffer *buffer,
                                                int x, int y) {
  ColorData pixel_color = buffer->pixel(x, y);
  float greyscale = pixel_color.Luminance();
  ColorData greyscale_color = ColorData(greyscale, greyscale, greyscale);
  ColorData new_pixel_color = ImageToolsMath::Lerp(greyscale_color,
                                                   pixel_color, scale());
  return new_pixel_color;
}

}  /* namespace image_tools */
