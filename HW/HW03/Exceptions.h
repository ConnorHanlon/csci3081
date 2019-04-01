//  Copyright 2018 Prof. Keefe

#ifndef HW03_EXCEPTIONS_H_
#define HW03_EXCEPTIONS_H_

/* Author: Eric Van Wyk
   Date created: October 20, 2009.
 */

#include <string>

class InvalidData {
 public:
    explicit InvalidData(std::string);
    ~InvalidData();
    std::string get_msg();

 private:
    std::string msg;
};

#endif  //  HW03_EXCEPTIONS_H_
