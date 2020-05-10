//
// Created by radugrecu97 on 5/9/20.
//

#include <GameManager.h>
#include <PegManager.h>
#include <GameState.h>
#include <SettingsManager.h>
#include <status_codes.h>
#include <setting_ids.h>
#include <Util.h>

#include <memory>

GameManager::GameManager() {
    this->pegManager = std::make_unique<PegManager>();
    this->pegManager->setCodePegs({ "R", "O", "Y", "G", "B", "I"});
    this->pegManager->setKeyPegPosition("B");
    this->pegManager->setKeyPegColor("W");
    this->gameState = std::make_unique<GameSate>();
    this->settingsManager = std::make_unique<SettingsManager>();
}


void GameManager::resetGame() {
    this->gameState->setCode(this->generateCode());
    this->gameState->setGuess("");
    this->gameState->setFeedback("");
    this->gameState->setTurnCount(0);
}

template<typename S>
auto select_random(const S &s, size_t n) {
    auto it = std::begin(s);
    // 'advance' the iterator n times
    std::advance(it,n);
    return it;
}

std::string GameManager::generateCode() {

    int size = 4;
    std::string code = "";
    std::set<std::string> codePool;

    std::unique_ptr<IUtil> util(new Util());
    std::set<std::string> pegPool = this->pegManager->getCodePegs();

    if (this->settingsManager->getAllowBlanks())
        pegPool.insert("*");

    // refresh random sequence
    srand(time(NULL));
    for (int i=0; i<size; i++) {

        auto r = rand() % pegPool.size(); // not _really_ random
        auto n = *select_random(pegPool, r);

        // retry selection to avoid duplicates
        if (!this->settingsManager->getAllowDuplicates())
            while (!codePool.insert(n).second) {
                // if element was inserted
                r = rand() % pegPool.size(); // not _really_ random
                n = *select_random(pegPool, r);
            }

        code.append(n);
    }
    this->gameState->setCode(code);
    return code;
}

std::string GameManager::generateFeedback() {

    std::set<int> blacklistIndex;
    std::string guess = this->gameState->getGuess(),
                code = this->gameState->getCode(),
                feedback = "";

    uint8_t size = code.size();
    // find pegs matching color AND position
    for (int i=0; i < size; i++) {
        if (guess[i] == code[i]) {
            feedback.append(this->pegManager->getKeyPegPosition());
            blacklistIndex.insert(i);
        }
    }

    // find pegs matching color only
    for (int i=0; i < size; i++) {

            // peg not found
            for (int j=0; j < size; j++) {
                if (blacklistIndex.find(j) == blacklistIndex.end())
                    if (i != j)
                        // this code peg wasn't matched
                        if (guess[i] == code[j]) {
                            feedback.append(this->pegManager->getKeyPegColor());
                            blacklistIndex.insert(j);
                            break;
                        }
            }
    }

    int feedbackSize = feedback.size();
    for (int i=0; i< size - feedbackSize; i++) {
        feedback.append("*");
    }

    this->gameState->setFeedback(feedback);
    return feedback;
}

int8_t GameManager::makeGuess() {
    this->generateFeedback();

    if (this->gameState->getGuess() == this->gameState->getCode())
        return codes::SUCCESS;
    else {
        return codes::FAILURE;
    }
}

int8_t GameManager::replaceCodePeg(std::string oldColor, std::string newColor) {
    return this->pegManager->replaceCodePeg(oldColor, newColor);
}

int8_t GameManager::setCode(std::string code) {
    int8_t statusCode = this->validateInput(code);

    if (statusCode != codes::SUCCESS)
        return statusCode;

    this->gameState->setCode(code);
    return codes::SUCCESS;
}

int8_t GameManager::setGuess(std::string guess) {
    int8_t statusCode = this->validateInput(guess);

    if (statusCode != codes::SUCCESS)
        return statusCode;

    this->gameState->setGuess(guess);
    return codes::SUCCESS;
}

int8_t GameManager::validateInput(std::string str) {
    int size = 4;

    // check code size
    if (str.size() != size) {
        return codes::INVALID_SIZE;
    }

    // check if code is valid
    std::unique_ptr<IUtil> util(new Util());

    if (this->getSettingsManager()->getAllowBlanks()) {
        if (util->validateUpperLettersAndStar(str) == codes::INVALID_INPUT)
            // invalid color
            return codes::INVALID_INPUT;
    } else {
        if (util->validateUpperLetters(str) == codes::INVALID_INPUT)
            // invalid color
            return codes::INVALID_INPUT;
    }

    if (!this->getSettingsManager()->getAllowDuplicates())
        // check if all pegs are unique
        if (util->countUniqueCharacters(str) != size)
            return codes::DUPLICATE_DATA;

    return codes::SUCCESS;
}

ISettingsManager* GameManager::getSettingsManager() {
    return this->settingsManager.get();
}

IGameState *GameManager::getGameState() {
    return this->gameState.get();
}

IPegManager *GameManager::getPegManager() {
    return this->pegManager.get();
}

int8_t GameManager::changeSetting(uint8_t settingId, std::string value) {
    std::unique_ptr<IUtil> util = std::make_unique<Util>();
    int8_t statusCode;
    switch (settingId) {

        case (setting_ids::MAX_TURNS):
            statusCode = util->validateNumbers(value);
            if (statusCode == codes::SUCCESS)
                this->settingsManager->setMaxTurns(std::stoi(value));
            return statusCode;

        case (setting_ids::BLANKS):
            if (value == "y") {
                this->settingsManager->setAllowBlanks(true);
            } else if (value == "n") {
                this->settingsManager->setAllowBlanks((false));
            } else {
                return codes::INVALID_INPUT;
            }
            return codes::SUCCESS;

        case (setting_ids::DUPLICATES):
            if (value == "y") {
                this->settingsManager->setAllowDuplicates(true);
            } else if (value == "n") {
                this->settingsManager->setAllowDuplicates((false));
            } else {
                return codes::INVALID_INPUT;
            }
            return codes::SUCCESS;

        case (setting_ids::CODE_PEG_COLOR):
            if (util->validateUpperLetters(value) == codes::SUCCESS)
                if (util->countUniqueCharacters(value) == 6) {
                    std::set<std::string> colorSet;
                    std::string s;
                    for (auto c : value) {
                        colorSet.insert(std::string(1, c));
                    }
                    this->pegManager->setCodePegs(colorSet);
                    return codes::SUCCESS;
                }
            return codes::INVALID_INPUT;

        case (setting_ids::KEY_PEG_COLOR):
            if (util->validateUpperLetters(value) == codes::SUCCESS)
                if (util->countUniqueCharacters(value) == 2) {
                    this->pegManager->setKeyPegColor(std::string(1, value[0]));
                    this->pegManager->setKeyPegPosition(std::string(1, value[1]));
                    return codes::SUCCESS;
                }
            return codes::INVALID_INPUT;
        default:
            break;
    }
    return 0;
}


