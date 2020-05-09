//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_ISETTINGSMANAGER_H
#define MASTERMIND_ISETTINGSMANAGER_H

#include <cstdint>

class ISettingsManager {
public:
    virtual int8_t setMaxTurns(int8_t count) = 0;
    virtual int8_t setAllowBlanks(bool state) = 0;
    virtual int8_t setAllowDuplicates(bool state) = 0;
    virtual int8_t getMaxTurns() = 0;
    virtual bool getAllowBlanks() = 0;
    virtual bool getAllowDuplicates() = 0;
};

#endif //MASTERMIND_ISETTINGSMANAGER_H
