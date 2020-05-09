//
// Created by radugrecu97 on 5/9/20.
//

#include <PegManager.h>
#include <Util.h>


PegManager::PegManager() = default;

int8_t PegManager::replaceCodePeg(std::string oldColor, std::string newColor) {
    //  validate that the color to be replaced exists in the set
    if (this->codePegs.find(oldColor) == this->codePegs.end()) {
        // color to be replaced isn't part of the set
        return -1;
    }

    //  validate that the new color exists in the set
    if (this->codePegs.find(newColor) == this->codePegs.end()) {
        // new color doesn't exist
        this->codePegs.erase(oldColor);
        this->codePegs.insert(newColor);
        return 1;
    } else {
        // new color already present
        return 0;
    }
}

int8_t PegManager::setCodePegs(std::set<std::string> colorSet) {

    // 6 according to the rules
    if (colorSet.size() != 6) {
        return -1;
    }

    IUtil *util = new Util();

    // check if colors are vaild
    for(auto f : colorSet) {
        if (util->validateUpperLetters(f) == -1)
            // invalid color
            return 0;
    }

    this->codePegs = colorSet;

    return 1;
}

int8_t PegManager::setKeyPegColor(std::string color) {
    IUtil *util = new Util();

    // a "color" must only be represented by Uppercase Letters
    if (util->validateUpperLetters(color) == -1)
    {
        // color is invalid
        return -1;
    }

    // check if the other key peg already has this color
    if (this->keyPegPosition == color)
    {
        // color is taken
        return 0;
    }
    else {
        // color is not taken
        this->keyPegColor = color;
        return 1;
    }

}


int8_t PegManager::setKeyPegPosition(std::string color) {
    IUtil *util = new Util();

    // a "color" must only be represented by Uppercase Letters
    if (util->validateUpperLetters(color) == -1)
    {
        // color is invalid
        return -1;
    }

    // check if the other key peg already has this color
    if (this->keyPegColor == color)
    {
        // color is taken
        return 0;
    }
    else {
        // color is not taken
        this->keyPegPosition = color;
        return 1;
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

