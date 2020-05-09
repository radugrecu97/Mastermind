//
// Created by radugrecu97 on 5/9/20.
//

#include <SettingsManager.h>

SettingsManager::SettingsManager() = default;

int8_t SettingsManager::setMaxTurns(int8_t count) {
    this->maxTurns = count;
    return 1;
}

int8_t SettingsManager::setAllowBlanks(bool state) {
    this->allowBlanks = state;
    return 1;
}

int8_t SettingsManager::setAllowDuplicates(bool state) {
    this->allowDuplicates = state;
    return 1;
}

int8_t SettingsManager::getMaxTurns() {
    return this->maxTurns;
}

bool SettingsManager::getAllowBlanks() {
    return this->allowBlanks;
}

bool SettingsManager::getAllowDuplicates() {
    return this->allowDuplicates;
}



