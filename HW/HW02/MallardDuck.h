//
//  MallardDuck.h
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#ifndef HW02_MALLARDDUCK_H_
#define HW02_MALLARDDUCK_H_

#include <string>
#include "Duck.h"

class MallardDuck : public Duck {
 public:
    MallardDuck();
    ~MallardDuck();
    std::string getDescription();
};

#endif  //  HW02_MALLARDDUCK_H_
