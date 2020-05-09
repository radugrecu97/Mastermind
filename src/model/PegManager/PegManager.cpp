//
// Created by radugrecu97 on 5/9/20.
//

#include <PegManager.h>

std::set<IPeg*> IPegManager::getCodePegs() {
    return this->codePegs;
}

IPeg *IPegManager::getKeyPegColor() {
    return this->keyPegColor;
}

IPeg *IPegManager::getKeyPegPosition() {
    return this->keyPegPosition;
}

uint8_t IPegManager::replaceCodePeg(std::string color) {
    if (this->codePegs.find(std::move(color)) !=)
    return 0;
}

uint8_t IPegManager::replaceKeyPeg(std::string color) {
    return 0;
}


