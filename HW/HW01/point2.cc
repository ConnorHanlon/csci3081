#include <math.h>
#include "HW/HW01/point2.h"
//  Copyright 2018 Prof. Keefe
using std::pow;
using std::sqrt;

Point2::Point2() {
  x_ = 0.0;
  y_ = 0.0;
}

Point2::Point2(float x, float y) {
  x_ = x;
  y_ = y;
}

Point2::~Point2() {}

float Point2::DistanceBetween(Point2 other_p) {
  float d1 = pow(other_p.GetX() - x_, 2);
  float d2 = pow(other_p.GetY() - y_, 2);
  return sqrt(d1 + d2);
}

float Point2::GetX() {
  return x_;
}

float Point2::GetY() {
  return y_;
}

void Point2::SetX(float x) {
  x_ = x;
}

void Point2::SetY(float y) {
  y_ = y;
}
