/**
This file is part of the CSCI-3081W Project Support Code, which was developed
at the University of Minnesota.

This code is to be used for student coursework.  It is not an open source
project.
Copyright (c) 2015-2018 Daniel Keefe, TAs, & Regents of the University of
Minnesota.

Original Author(s) of this File:
  Seth Johnson, 4/4/2015, University of Minnesota

Author(s) of Significant Updates/Modifications to the File:
  Connor Hanlon
*/
#include "imagetools/tool_blur.h"

#include "imagetools/convolution_filter_blur.h"
#include "imagetools/color_data.h"
#include "imagetools/mask_factory.h"


namespace image_tools {

/** Create base blur tool with a default blur radius of 5. */
ToolBlur::ToolBlur() {
  float radius = 5.0;
  blur_filter_ = ConvolutionFilterBlur(radius);
  blur_filter_.SetUpFilter();

  // the blur operation is not fast, so space the repeated applications of the
  // stamp out as far as we can get away with while still having it look good
  // 1/3 overlap is pretty good for this.
  stamp_overlap_ = 0.333;
}

/** Must CleanupFilter when done with blur tool. */
ToolBlur::~ToolBlur() {
  blur_filter_.CleanupFilter();
}

FloatMatrix* ToolBlur::CreateMask(float radius) {
  return MaskFactory::CreateLinearFalloffMask(radius);
}

ColorData ToolBlur::LookupPaintColor(int x, int y) {
  ColorData new_color = blur_filter_.CalculateFilteredPixel(buffer_, x, y);
  return new_color;
}

} /* namespace image_tools */


// ideas:
