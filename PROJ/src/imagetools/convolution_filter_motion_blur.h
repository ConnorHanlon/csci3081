/*
Copyright (c) 2018 Connor Hanlon
*/
#ifndef IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_
#define IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_

#include <string>
#include <cmath>
#include <map>
#include <vector>
#include "imagetools/convolution_filter.h"
#include "imagetools/float_matrix.h"

namespace image_tools {

/** @brief "Blurs the image by convolving it with an appropriate motion-blur
kernel. Supports four possible blur directions (North/South, East/West,
Northeast/Southwest, and Northwest/Southeast) and blurs according to the amount
specified in the GUI." - Documentation Description. */
class ConvolutionFilterMotionBlur : public ConvolutionFilter {
 public:
  /// Four possible directions of blur are supported
  enum BlurDir { BLUR_DIR_N_S, BLUR_DIR_E_W, BLUR_DIR_NE_SW, BLUR_DIR_NW_SE };

   /** Sets default motion blur filter to a radius of 1 and a blur direction out
   Northwest/Southeast. */
  ConvolutionFilterMotionBlur();

  ConvolutionFilterMotionBlur(float radius, BlurDir dir);

  virtual ~ConvolutionFilterMotionBlur();

  /** Baased on the direction of the blur, a kernel is created of size
  ((radius * 2) + 1), and sets all values in kernel to 1 except for where the
  direction blur occurs, which are set to 1. All values are then multiplied by
  a factor of 1/sum(kernel), and the kernel is returned. */
  FloatMatrix *CreateKernel() override;

  /** Returns the radius of the kernel. Possible bug, the radius actually
  doesn't return an exact radius but a random float between r and r+1. Using
  floor to get the exact radius*/
  float radius() const { return floor(radius_); }
  void set_radius(float r);

  static std::string MotionBlurDirectionName(BlurDir dir) {
    return mblur_dir_names_.find(dir)->second;
  }

  BlurDir direction();

 private:
  float radius_;
  BlurDir dir_;
  static const std::map<BlurDir, std::string> mblur_dir_names_;
};

}  //  namespace image_tools

#endif  //  IMAGETOOLS_CONVOLUTION_FILTER_MOTION_BLUR_H_
