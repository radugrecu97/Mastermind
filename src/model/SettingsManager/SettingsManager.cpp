//
// Created by radugrecu97 on 5/9/20.
//

#include <SettingsManager.h>
#include <status_codes.h>

SettingsManager::SettingsManager() {
    this->maxTurns = 8;
    this->allowDuplicates = false;
    this->allowBlanks = false;
};

int8_t SettingsManager::setMaxTurns(uint8_t count) {
    this->maxTurns = count;
    return codes::SUCCESS;
}

int8_t SettingsManager::setAllowBlanks(bool state) {
    this->allowBlanks = state;
    return codes::SUCCESS;
}

int8_t SettingsManager::setAllowDuplicates(bool state) {
    this->allowDuplicates = state;
    return codes::SUCCESS;
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



