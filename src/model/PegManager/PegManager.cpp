//
// Created by radugrecu97 on 5/9/20.
//

#include <PegManager.h>
#include <Util.h>
#include <bits/unique_ptr.h>
#include <error_codes.h>

PegManager::PegManager() = default;

int8_t PegManager::replaceCodePeg(std::string oldColor, std::string newColor) {

    //  check if old color exists in the set
    if (this->codePegs.find(oldColor) == this->codePegs.end()) {
        // color to be replaced isn't part of the set
        return codes::INVALID_INPUT;
    }

    // check if new color is valid
    std::unique_ptr<IUtil> util(new Util());
    if (util->validateUpperLetters(newColor) == codes::INVALID_INPUT)
        return codes::INVALID_INPUT;

    //  check if new color exists in the set already
    if (this->codePegs.find(newColor) == this->codePegs.end()) {
        // new color doesn't exist
        this->codePegs.erase(oldColor);
        this->codePegs.insert(newColor);
        return codes::SUCCESS;
    } else {
        // new color already present
        return codes::DUPLICATE_DATA;
    }
}

int8_t PegManager::setCodePegs(std::set<std::string> colorSet) {

    // 6 according to the rules
    if (colorSet.size() != 6) {
        return codes::INVALID_SIZE;
    }

    std::unique_ptr<IUtil> util(new Util());

    // check if colors are vaild
    for(const auto& c : colorSet) {
        if (util->validateUpperLetters(c) == codes::INVALID_INPUT)
            // invalid color
            return codes::INVALID_INPUT;
    }

    this->codePegs = colorSet;

    return codes::SUCCESS;
}

int8_t PegManager::setKeyPegColor(std::string color) {
    std::unique_ptr<IUtil> util(new Util());

    // a "color" must only be represented by Uppercase Letters
    if (util->validateUpperLetters(color) == codes::INVALID_INPUT)
    {
        // color is invalid
        return codes::INVALID_INPUT;
    }

    // check if the other key peg already has this color
    if (this->keyPegPosition == color)
    {
        // color is taken
        return codes::DUPLICATE_DATA;
    }
    else {
        // color is not taken
        this->keyPegColor = color;
        return codes::SUCCESS;
    }

}


int8_t PegManager::setKeyPegPosition(std::string color) {
    std::unique_ptr<IUtil> util(new Util());

    // a "color" must only be represented by Uppercase Letters
    if (util->validateUpperLetters(color) == codes::INVALID_INPUT)
    {
        // color is invalid
        return codes::INVALID_INPUT;
    }

    // check if the other key peg already has this color
    if (this->keyPegColor == color)
    {
        // color is taken
        return codes::DUPLICATE_DATA;
    }
    else {
        // color is not taken
        this->keyPegPosition = color;
        return codes::SUCCESS;
    }
}

std::set<std::string> PegManager::getCodePegs() {
    return this->codePegs;
}

std::string PegManager::getKeyPegColor() {
    return this->keyPegColor;
}

std::string PegManager::getKeyPegPosition() {
    return this->keyPegPosition;
}

