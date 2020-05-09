//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_GAMESTATE_H
#define MASTERMIND_GAMESTATE_H

#include <IGameState.h>

class GameSate: public IGameState {
private:
    std::string code;
    std::string guess;
    std::string feedback;
    uint8_t turnCount{};
    uint8_t maxTurns{};
    bool allowBlanks{};
    bool allowDuplicates{};
public:
    GameSate();
    void nextTurn() override;
    int8_t setCode(std::string codeStr) override;
    int8_t setGuess(std::string guessStr) override;
    int8_t setFeedback(std::string feedbackStr) override;
    int8_t setTurnCount(int8_t count) override;
    void setMaxTurns(int8_t count) override;
    void setAllowBlanks(bool state) override;
    void setAllowDuplicates(bool state) override;
    std::string getCode() override;
    std::string getGuess() override;
    std::string getFeedback() override;
    int8_t getTurnCount() override;
    int8_t getMaxTurns() override;
    bool getAllowBlanks() override;
    bool getAllowDuplicates() override;
};

#endif //MASTERMIND_GAMESTATE_H
