//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_IPEG_H
#define MASTERMIND_IPEG_H

#include <string>

class IPeg {
public:
    virtual void setColor(std::string color) = 0;
    virtual std::string getColor() = 0;
};

#endif //MASTERMIND_IPEG_H
