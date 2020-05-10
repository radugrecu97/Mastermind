//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_IGAMEMANAGER_H
#define MASTERMIND_IGAMEMANAGER_H

#include <string>
#include <cstdint>
#include <ISettingsManager.h>
#include <IPegManager.h>
#include <IGameState.h>

class IGameManager {
public:
    virtual void resetGame() = 0;
    virtual std::string generateCode() = 0;
    virtual std::string generateFeedback() = 0;
    virtual int8_t makeGuess() = 0;
    virtual int8_t replaceCodePeg(std::string oldColor, std::string newColor) = 0;
    virtual int8_t setCode(std::string code) = 0;
    virtual int8_t setGuess(std::string guess) = 0;
    virtual int8_t validateInput(std::string str) = 0;
    virtual ISettingsManager* getSettingsManager() = 0;
    virtual IGameState* getGameState() = 0;
    virtual IPegManager* getPegManager() = 0;
};

#endif //MASTERMIND_IGAMEMANAGER_H
