//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_IPEGMANAGER_H
#define MASTERMIND_IPEGMANAGER_H

#include <set>
#include <IPeg.h>

class IPegManager {
    virtual std::set<IPeg*> getCodePegs() = 0;
    virtual IPeg* getKeyPegColor() = 0;
    virtual IPeg* getKeyPegPosition() = 0;
    virtual uint8_t replaceCodePeg(std::string color) = 0;
    virtual uint8_t replaceKeyPeg(std::string color) = 0;
};

#endif //MASTERMIND_IPEGMANAGER_H
