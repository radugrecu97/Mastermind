//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_GAMEMANAGER_H
#define MASTERMIND_GAMEMANAGER_H

#include <IGameManager.h>
#include <IGameState.h>
#include <ISettingsManager.h>
#include <IPegManager.h>
#include <bits/unique_ptr.h>

class GameManager: public IGameManager {
private:
    std::unique_ptr<IGameState> gameState;
    std::unique_ptr<ISettingsManager> settingsManager;
    std::unique_ptr<IPegManager> pegManager;
public:
    GameManager();
    void resetGame() override;
    std::string generateCode() override;
    std::string generateFeedback() override;
    int8_t makeGuess() override;
    int8_t replaceCodePeg(std::string oldColor, std::string newColor) override;
    int8_t setCode(std::string code) override;
    int8_t setGuess(std::string guess) override;
    int8_t validateInput(std::string) override;
    ISettingsManager* getSettingsManager() override;
    IGameState* getGameState() override;
    IPegManager* getPegManager() override;
};


#endif //MASTERMIND_GAMEMANAGER_H
