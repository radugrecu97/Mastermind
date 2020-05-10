//
// Created by radugrecu97 on 5/9/20.
//

#include <GameState.h>
#include <IUtil.h>
#include <bits/unique_ptr.h>
#include <Util.h>
#include <error_codes.h>

GameSate::GameSate() = default;

void GameSate::setCode(std::string codeStr) {
    this->code = codeStr;
}

void GameSate::setGuess(std::string guessStr) {
    this->guess = guessStr;
}

void GameSate::setFeedback(std::string feedbackStr) {
    this->feedback = feedbackStr;
}

void GameSate::setTurnCount(int8_t count) {
    this->turnCount = count;
}

std::string GameSate::getCode() {
    return this->code;
}

std::string GameSate::getGuess() {
    return this->guess;
}

std::string GameSate::getFeedback() {
    return this->feedback;
}

int8_t GameSate::getTurnCount() {
    return this->turnCount;
}



