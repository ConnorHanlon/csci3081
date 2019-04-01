/*
Copyright (c) 2018 Connor Hanlon
*/
// #include <cmath>
#include "imagetools/convolution_filter_motion_blur.h"
#include <map>

namespace image_tools {
const std::map<ConvolutionFilterMotionBlur::BlurDir, std::string>
    ConvolutionFilterMotionBlur::mblur_dir_names_ = {
        {BLUR_DIR_N_S, "North/South"},
        {BLUR_DIR_E_W, "East/West"},
        {BLUR_DIR_NE_SW, "Northeast/Southwest"},
        {BLUR_DIR_NW_SE, "Northwest/Southeast"}};

ConvolutionFilterMotionBlur::ConvolutionFilterMotionBlur() {
  radius_ = 1.0;
  dir_ = BLUR_DIR_NW_SE;
}

ConvolutionFilterMotionBlur::ConvolutionFilterMotionBlur(float radius,
                                                        BlurDir dir) :
                                                        radius_(radius),
                                                        dir_(dir) {}

ConvolutionFilterMotionBlur::~ConvolutionFilterMotionBlur() {}

FloatMatrix *ConvolutionFilterMotionBlur::CreateKernel() {
  FloatMatrix *new_kernel = new FloatMatrix(radius());
  new_kernel->Scale(0);
  if (dir_ == BLUR_DIR_NW_SE) {
    // If Northwest/Southeast, set all values along diagonal to 1.
    for (int w = 0; w < new_kernel->width(); w++) {
      new_kernel->set_value(w, w, 1.0);
    }
  } else if (dir_ == BLUR_DIR_NE_SW) {
    // If Northeast/Southwest, set all values along opposite diagonal to 1.
    int diag_val = 0;
    for (int w = new_kernel->width()-1; w >= 0; w--) {
      new_kernel->set_value(w, diag_val, 1.0);
      diag_val += 1;
    }
  } else if (dir_ == BLUR_DIR_N_S) {
    // If North/South, set all values at the middle of the width of the kernel
    // to 1.
    float middle = radius();
    for (int h = 0; h < new_kernel->height(); h++) {
      new_kernel->set_value(middle, h, 1.0);
    }
  } else {  // dir_ ==  "East/West"
    // If East/West, set all values at the middle of the height of the kernel
    // to 1.
    float middle = radius();
    for (int w = 0; w < new_kernel->width(); w++) {
      new_kernel->set_value(w, middle, 1.0);
    }
  }
  new_kernel->Normalize();
  return new_kernel;
}

ConvolutionFilterMotionBlur::BlurDir ConvolutionFilterMotionBlur::direction() {
  return dir_;
}

void ConvolutionFilterMotionBlur::set_radius(float r) {
  radius_ = r;
}


}  //  namespace image_tools
