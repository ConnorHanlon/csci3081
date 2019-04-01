//
//  MuteQuack.h
//
//  Created by Seth Johnson on 2/5/15.
//  Copyright (c) 2015 Seth Johnson. All rights reserved.
//

#ifndef HW02_MUTEQUACK_H_
#define HW02_MUTEQUACK_H_

#include "QuackBehavior.h"

class MuteQuack : public QuackBehavior {
 public:
    MuteQuack() {}
    ~MuteQuack() {}
    void quack();
};

#endif  //  HW02_MUTEQUACK_H_
