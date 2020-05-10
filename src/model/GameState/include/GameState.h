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
//    uint8_t maxTurns{};
//    bool allowBlanks{};
//    bool allowDuplicates{};
    std::vector<std::string> guessHistory;
public:
    GameSate();
    void setCode(std::string codeStr) override;
    void setGuess(std::string guessStr) override;
    void setFeedback(std::string feedbackStr) override;
    void setTurnCount(int8_t count) override;
    std::string getCode() override;
    std::string getGuess() override;
    std::string getFeedback() override;
    int8_t getTurnCount() override;
    void appendHistory(std::string) override;
    void clearHistory() override;
    std::vector<std::string> getHistory() override;
};

#endif //MASTERMIND_GAMESTATE_H
