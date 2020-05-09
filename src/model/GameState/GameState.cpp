//
// Created by radugrecu97 on 5/9/20.
//

#include <GameState.h>
#include <IUtil.h>
#include <bits/unique_ptr.h>
#include <Util.h>
#include <error_codes.h>

GameSate::GameSate() = default;

int8_t GameSate::setCode(std::string codeStr) {

    // check code size
    if (codeStr.size() != 4) {
        return codes::INVALID_SIZE;
    }

    // check if code is valid
    std::unique_ptr<IUtil> util(new Util());
    if (util->validateUpperLetters(codeStr) == codes::INVALID_INPUT)
        // invalid color
        return codes::INVALID_INPUT;

    this->code = codeStr;
    return codes::SUCCESS;
}

int8_t GameSate::setGuess(std::string guessStr) {
    // check guess size
    if (guessStr.size() != 4) {
        return codes::INVALID_SIZE;
    }

    // check if guess is valid
    std::unique_ptr<IUtil> util(new Util());
    if (util->validateUpperLetters(guessStr) == codes::INVALID_INPUT)
        // invalid color
        return codes::INVALID_INPUT;

    this->guess = guessStr;
    return codes::SUCCESS;
}

int8_t GameSate::setFeedback(std::string feedbackStr) {
    // check feedback size
    if (feedbackStr.size() != 4) {
        return codes::INVALID_SIZE;
    }

    // check if feedback is valid
    std::unique_ptr<IUtil> util(new Util());
    if (util->validateUpperLetters(feedbackStr) == codes::INVALID_INPUT)
        // invalid feedback
        return codes::INVALID_INPUT;

    this->guess = feedbackStr;
    return codes::SUCCESS;
}

int8_t GameSate::setTurnCount(int8_t count) {
    this->turnCount = count;
    return 0;
}

void GameSate::setMaxTurns(int8_t count) {
    this->maxTurns = count;
}

void GameSate::setAllowBlanks(bool state) {
    this->allowBlanks = state;
}

void GameSate::setAllowDuplicates(bool state) {
    this->allowDuplicates = state;
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

int8_t GameSate::getMaxTurns() {
    return this->maxTurns;
}

bool GameSate::getAllowBlanks() {
    return this->allowBlanks;
}

bool GameSate::getAllowDuplicates() {
    return this->allowDuplicates;
}



