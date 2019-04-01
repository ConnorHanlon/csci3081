//
//  Squeak.h
//
//  Created by Seth Johnson on 2/5/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef HW02_SQUEAK_H_
#define HW02_SQUEAK_H_

#include "QuackBehavior.h"

class Squeak : public QuackBehavior {
 public:
    Squeak() {}
    ~Squeak() {}
    void quack();
};

#endif  //  HW02_SQUEAK_H_
