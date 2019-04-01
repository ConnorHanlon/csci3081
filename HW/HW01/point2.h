//  Copyright 2018 Prof. Keefe

#ifndef HW01_POINT2_H_
#define HW01_POINT2_H_

class Point2{
 public:
    Point2();
    Point2(float x, float y);
    virtual ~Point2();

    float DistanceBetween(Point2 other_p);

    float GetX();
    float GetY();

    void SetX(float x);
    void SetY(float y);

 private:
    float x_;
    float y_;
};

#endif  //  HW01_POINT2_H_
