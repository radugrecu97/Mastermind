//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_PEGMANAGER_H
#define MASTERMIND_PEGMANAGER_H

#include <set>
#include <IPeg.h>

class IPegManager {
private:
    std::set<IPeg*> codePegs;
    IPeg *keyPegColor;
    IPeg *keyPegPosition;
public:
    std::set<IPeg*> getCodePegs();
    IPeg* getKeyPegColor();
    IPeg* getKeyPegPosition();
    uint8_t replaceCodePeg(std::string color);
    uint8_t replaceKeyPeg(std::string color);
};

#endif //MASTERMIND_PEGMANAGER_H
