// This follows the Google Style Guide:
//    https://google.github.io/styleguide/cppguide.html
// Style correctness verified by cpplint (pip install cpplint)

// Copyright 2018 <Kevin D. Wendt>


#include <math.h>  // FOR SQRT()
#include <iostream>
#include <fstream>
#include <string>

#include "HW/HW01/point2.h"

int main() {
  Point2 p00;
  Point2 p11(1.0, 1.0);
  Point2 p21(2.0, 1.0);
  Point2 p12(1.0, 2.0);
  Point2 pPI45(sqrt(2)/2, sqrt(2)/2);

  Point2 p_a(3.0, 5.0), p_b(4.0, 4.0);

  std::cout << "(1,1) to (2,1) is " << p11.DistanceBetween(p21) << std::endl;
  std::cout << "(2,1) to (1,2) is " << p21.DistanceBetween(p12) << std::endl;
  std::cout << "(0,0) to (sqrt(2)/2, sqrt(2)/2) is ";
  std::cout << p00.DistanceBetween(pPI45) << std::endl;
  std::cout << "a to b is " << p_a.DistanceBetween(p_b) << std::endl;

  return 0;
}
