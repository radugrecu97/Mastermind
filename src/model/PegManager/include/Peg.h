//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_PEG_H
#define MASTERMIND_PEG_H

#include <IPeg.h>
#include <string>

class Peg: public IPeg {
private:
    std::string color;
public:
    explicit Peg(std::string color);
    void setColor(std::string color);
    std::string getColor();
};

#endif //MASTERMIND_PEG_H
