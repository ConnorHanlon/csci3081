#include "gtest/gtest.h"
#include <iostream>
#include <math.h>
#include "point2.h"


class Point2Test : public ::testing::Test {
  void SetUp( ) { 
    // code here will execute just before the test ensues 
	//Point2 p00;
	p11 = Point2(1.0, 1.0);
	p21 = Point2(2.0, 1.0);
	p12 = Point2(1.0, 2.0);
	pPI45 = Point2(sqrt(2)/2, sqrt(2)/2);
	p_a = Point2(3.0, 5.0);
	p_b = Point2(4.0, 4.0);
  }
  protected:
    Point2 p00;
	Point2 p11;
	Point2 p21;
	Point2 p12;
	Point2 pPI45;
	Point2 p_a;
	Point2 p_b;
};

TEST_F(Point2Test, DistBtwnBothPositive) {
  EXPECT_FLOAT_EQ(p11.DistanceBetween(p21), 1.0);
  EXPECT_FLOAT_EQ(p21.DistanceBetween(p12), sqrt(2));
  EXPECT_FLOAT_EQ(p00.DistanceBetween(pPI45), 1.0);
  EXPECT_FLOAT_EQ(p_a.DistanceBetween(p_b), sqrt(2));
}

TEST_F(Point2Test, DistBtwnInverses) {
  EXPECT_FLOAT_EQ(p11.DistanceBetween(p21), p21.DistanceBetween(p11));
  EXPECT_FLOAT_EQ(p21.DistanceBetween(p12), p12.DistanceBetween(p21));
  EXPECT_FLOAT_EQ(p00.DistanceBetween(pPI45), pPI45.DistanceBetween(p00));
  EXPECT_FLOAT_EQ(p_a.DistanceBetween(p_b), p_b.DistanceBetween(p_a));
}