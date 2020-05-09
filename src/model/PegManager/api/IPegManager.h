//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_IPEGMANAGER_H
#define MASTERMIND_IPEGMANAGER_H

#include <string>
#include <set>

class IPegManager {
public:
    virtual int8_t replaceCodePeg(std::string oldColor, std::string newColor) = 0;
    virtual int8_t setCodePegs(std::set<std::string> colorSet) = 0;
    virtual int8_t setKeyPegColor(std::string color) = 0;
    virtual int8_t setKeyPegPosition(std::string color) = 0;
    virtual std::set<std::string> getCodePegs() = 0;
    virtual std::string getKeyPegColor() = 0;
    virtual std::string getKeyPegPosition() = 0;
};

#endif //MASTERMIND_IPEGMANAGER_H
