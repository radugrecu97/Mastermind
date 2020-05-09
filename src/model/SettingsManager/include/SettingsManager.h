//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_SETTINGSMANAGER_H
#define MASTERMIND_SETTINGSMANAGER_H

#include <ISettingsManager.h>

class SettingsManager: public ISettingsManager {
private:
    uint8_t maxTurns{};
    bool allowBlanks{};
    bool allowDuplicates{};
public:
    SettingsManager();
    int8_t setMaxTurns(uint8_t count) override;
    int8_t setAllowBlanks(bool state) override;
    int8_t setAllowDuplicates(bool state) override;
    int8_t getMaxTurns() override;
    bool getAllowBlanks() override;
    bool getAllowDuplicates() override;
};


#endif //MASTERMIND_SETTINGSMANAGER_H
