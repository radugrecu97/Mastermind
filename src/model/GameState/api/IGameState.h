//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_IGAMESTATE_H
#define MASTERMIND_IGAMESTATE_H

#include <string>
#include <vector>

class IGameState {
public:
    virtual void setCode(std::string codeStr) = 0;
    virtual void setGuess(std::string guessStr) = 0;
    virtual void setFeedback(std::string feedbackStr) = 0;
    virtual void setTurnCount(int8_t count) = 0;
    virtual std::string getCode() = 0;
    virtual std::string getGuess() = 0;
    virtual std::string getFeedback() = 0;
    virtual int8_t getTurnCount() = 0;
};

#endif //MASTERMIND_IGAMESTATE_H
