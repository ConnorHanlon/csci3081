//
//  Quack.h
//
//  Created by Seth Johnson on 2/4/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef HW02_QUACK_H_
#define HW02_QUACK_H_

#include "QuackBehavior.h"

class Quack : public QuackBehavior {
 public:
    Quack() {}
    ~Quack() {}
    void quack();
};

#endif  //  HW02_QUACK_H_
