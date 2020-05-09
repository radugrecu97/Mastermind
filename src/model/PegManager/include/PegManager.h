//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_PEGMANAGER_H
#define MASTERMIND_PEGMANAGER_H

#include <set>
#include <IPegManager.h>

class PegManager: public IPegManager {
private:
    std::set<std::string> codePegs;
    std::string keyPegColor;
    std::string keyPegPosition;
public:
    PegManager();
    int8_t replaceCodePeg(std::string oldColor, std::string newColor) override;
    int8_t setCodePegs(std::set<std::string> colorSet) override ;
    int8_t setKeyPegColor(std::string color) override;
    int8_t setKeyPegPosition(std::string color) override;
    std::set<std::string> getCodePegs() override;
    std::string getKeyPegColor() override;
    std::string getKeyPegPosition() override;
};

#endif //MASTERMIND_PEGMANAGER_H
