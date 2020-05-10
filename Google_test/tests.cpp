

//
// Created by radugrecu97 on 5/6/20.
//

#include "gtest/gtest.h"
#include <PegManager.h>
#include <Util.h>
#include <SettingsManager.h>
#include <GameState.h>
#include <error_codes.h>
#include <GameManager.h>
#include <string>
#include <algorithm>
// ************************************ Util ************************************

// validateUpperLetters
TEST(UtilTestSuite, VALIDATE_UPPER_LETTERS_SUCCESS) {
    // init
    std::unique_ptr<IUtil> util(new Util());

    int8_t result = util->validateUpperLetters("A");
    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(UtilTestSuite, VALIDATE_UPPER_LETTERS_FAIL_INVALID) {
    // init
    std::unique_ptr<IUtil> util(new Util());

    int8_t result = util->validateUpperLetters("*");
    ASSERT_EQ(result, codes::INVALID_INPUT);
}

// ************************************ PegManager ************************************

// setCodePegs

TEST(PegManagerTestSuite, SET_CODE_PEGS_SUCCESS) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "I"};

    int8_t result = pegManager->setCodePegs(colorSet);
    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(PegManagerTestSuite, SET_CODE_PEGS_FAIL_SIZE) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "B"};

    int8_t result = pegManager->setCodePegs(colorSet);
    ASSERT_EQ(result, codes::INVALID_SIZE);
}

TEST(PegManagerTestSuite, SET_CODE_PEGS_FAIL_INVALID) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "*"};

    int8_t result = pegManager->setCodePegs(colorSet);
    ASSERT_EQ(result, codes::INVALID_INPUT);
}

// setKeyPegColor

TEST(PegManagerTestSuite, SET_KEY_PEG_COLOR_SUCCESS) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::string keyPegColor = "W";
    std::string keyPegPosition = "B";
    pegManager->setKeyPegPosition(keyPegPosition);

    int8_t result = pegManager->setKeyPegColor(keyPegColor);
    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(PegManagerTestSuite, SET_KEY_PEG_COLOR_INVALID) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::string keyPegColor = "*";
    std::string keyPegPosition = "B";
    pegManager->setKeyPegPosition(keyPegPosition);

    int8_t result = pegManager->setKeyPegColor(keyPegColor);
    ASSERT_EQ(result, codes::INVALID_INPUT);
}

TEST(PegManagerTestSuite, SET_KEY_PEG_COLOR_DUPLICATE) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::string keyPegColor = "W";
    std::string keyPegPosition = "W";
    pegManager->setKeyPegPosition(keyPegPosition);

    int8_t result = pegManager->setKeyPegColor(keyPegColor);
    ASSERT_EQ(result, codes::DUPLICATE_DATA);
}

// setKeyPegPosition

TEST(PegManagerTestSuite, SET_KEY_PEG_POSITION_SUCCESS) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::string keyPegColor = "W";
    std::string keyPegPosition = "B";
    pegManager->setKeyPegColor(keyPegColor);

    int8_t result = pegManager->setKeyPegPosition(keyPegPosition);
    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(PegManagerTestSuite, SET_KEY_PEG_POSITION_INVALID) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::string keyPegColor = "W";
    std::string keyPegPosition = "*";
    pegManager->setKeyPegColor(keyPegColor);

    int8_t result = pegManager->setKeyPegPosition(keyPegPosition);
    ASSERT_EQ(result, codes::INVALID_INPUT);
}

TEST(PegManagerTestSuite, SET_KEY_PEG_POSITION_DUPLICATE) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::string keyPegColor = "W";
    std::string keyPegPosition = "W";
    pegManager->setKeyPegColor(keyPegColor);

    int8_t result = pegManager->setKeyPegPosition(keyPegPosition);
    ASSERT_EQ(result, codes::DUPLICATE_DATA);
}

// replaceCodePeg

TEST(PegManagerTestSuite, REPLACE_CODE_PEG_COLOR_SUCCESS) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "I"};
    pegManager->setCodePegs(colorSet);

    int8_t result = pegManager->replaceCodePeg("R",  "C");
    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(PegManagerTestSuite, REPLACE_CODE_PEG_COLOR_FAIL_OLD) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "I"};
    pegManager->setCodePegs(colorSet);

    int8_t result = pegManager->replaceCodePeg("Z",  "C");
    ASSERT_EQ(result, codes::INVALID_INPUT);
}

TEST(PegManagerTestSuite, REPLACE_CODE_PEG_COLOR_FAIL_NEW) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "I"};
    pegManager->setCodePegs(colorSet);

    int8_t result = pegManager->replaceCodePeg("R",  "Y");
    ASSERT_EQ(result, codes::DUPLICATE_DATA);
}

TEST(PegManagerTestSuite, REPLACE_CODE_PEG_COLOR_FAIL_INVALID) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "I"};
    pegManager->setCodePegs(colorSet);

    int8_t result = pegManager->replaceCodePeg("R",  "*");
    ASSERT_EQ(result, codes::INVALID_INPUT);
}

// getters

TEST(PegManagerTestSuite, GET_CODE_PEGS) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "I"};
    pegManager->setCodePegs(colorSet);

    bool result = pegManager->getCodePegs() == colorSet;
    ASSERT_EQ(result, true);
}

TEST(PegManagerTestSuite, GET_KEY_COLOR) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::string keyPegColor = "W";
    pegManager->setKeyPegColor(keyPegColor);

    bool result = pegManager->getKeyPegColor() == keyPegColor;
    ASSERT_EQ(result, true);
}

TEST(PegManagerTestSuite, GET_KEY_POSITION) {
    // init
    std::unique_ptr<IPegManager> pegManager(new PegManager());
    std::string keyPegPosition = "B";
    pegManager->setKeyPegPosition(keyPegPosition);

    bool result = pegManager->getKeyPegPosition() == keyPegPosition;
    ASSERT_EQ(result, true);
}

// ************************************ SettingsManager ************************************

TEST(SettingsManagerTestSuite, SET_MAX_TURNS) {
    // init
    std::unique_ptr<ISettingsManager> settingsManager(new SettingsManager());
    int8_t count = 8;
    settingsManager->setMaxTurns(count);

    bool result = count && settingsManager->getMaxTurns();
    ASSERT_EQ(result, true);
}

TEST(SettingsManagerTestSuite, SET_ALLOW_BLANKS) {
    // init
    std::unique_ptr<ISettingsManager> settingsManager(new SettingsManager());
    int8_t state = true;
    settingsManager->setAllowBlanks(state);

    bool result = state && settingsManager->getAllowBlanks();
    ASSERT_EQ(result, true);
}

TEST(SettingsManagerTestSuite, SET_ALLOW_DUPLICATES) {
    // init
    std::unique_ptr<ISettingsManager> settingsManager(new SettingsManager());
    int8_t state = true;
    settingsManager->setAllowDuplicates(state);

    bool result = state && settingsManager->getAllowDuplicates();
    ASSERT_EQ(result, true);
}

// ************************************ GameManager ************************************

TEST(GameManagerTestSuite, SET_CODE_SUCCESS) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    int8_t result = gameManager->setCode("ABCD");
    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(GameManagerTestSuite, SET_CODE_SUCCESS_DUPLICATES) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    gameManager->getSettingsManager()->setAllowDuplicates(true);
    int8_t result = gameManager->setCode("ABCC");
    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(GameManagerTestSuite, SET_CODE_SUCCESS_BLANKS) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    gameManager->getSettingsManager()->setAllowBlanks(true);
    int8_t result = gameManager->setCode("ABC*");
    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(GameManagerTestSuite, SET_CODE_SUCCESS_DUPLICATES_BLANKS) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    gameManager->getSettingsManager()->setAllowDuplicates(true);
    gameManager->getSettingsManager()->setAllowBlanks(true);
    int8_t result = gameManager->setCode("ABB*");
    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(GameManagerTestSuite, SET_CODE_FAILURE_SIZE) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    int8_t result = gameManager->setCode("ABC");
    ASSERT_EQ(result, codes::INVALID_SIZE);
}

TEST(GameManagerTestSuite, SET_CODE_FAILURE_INVALID) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    int8_t result = gameManager->setCode("1234");
    ASSERT_EQ(result, codes::INVALID_INPUT);
}

TEST(GameManagerTestSuite, SET_CODE_FAILURE_DUPLICATES) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    gameManager->getSettingsManager()->setAllowDuplicates(false);
    int8_t result = gameManager->setCode("ABCC");
    ASSERT_EQ(result, codes::DUPLICATE_DATA);
}

TEST(GameManagerTestSuite, SET_CODE_FAILURE_BLANKS) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    gameManager->getSettingsManager()->setAllowBlanks(false);
    int8_t result = gameManager->setCode("ABC*");
    ASSERT_EQ(result, codes::INVALID_INPUT);
}

TEST(GameManagerTestSuite, SET_CODE_FAILURE_DUPLICATES_BLANKS) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    gameManager->getSettingsManager()->setAllowDuplicates(false);
    gameManager->getSettingsManager()->setAllowBlanks(false);
    int8_t result = gameManager->setCode("ABB*");
    ASSERT_EQ(result, codes::INVALID_INPUT);
}

TEST(GameManagerTestSuite, MAKE_GUESS_SUCCESS) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    std::string seq = "ABCD";
    gameManager->setCode(seq);
    gameManager->setGuess(seq);
    int8_t result = gameManager->makeGuess();

    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(GameManagerTestSuite, MAKE_GUESS_SUCCESS_DUPLICATES) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    std::string seq = "ABCC";
    gameManager->getSettingsManager()->setAllowDuplicates(true);
    gameManager->setCode(seq);
    gameManager->setGuess(seq);
    int8_t result = gameManager->makeGuess();

    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(GameManagerTestSuite, MAKE_GUESS_SUCCESS_BLANKS) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    std::string seq = "ABC*";
    gameManager->getSettingsManager()->setAllowBlanks(true);
    gameManager->setCode(seq);
    gameManager->setGuess(seq);
    int8_t result = gameManager->makeGuess();

    ASSERT_EQ(result, codes::SUCCESS);
}

TEST(GameManagerTestSuite, MAKE_GUESS_SUCCESS_DUPLICATES_BLANKS) {
    // init
    std::unique_ptr<IGameManager> gameManager(new GameManager());
    std::string seq = "ABB*";
    gameManager->getSettingsManager()->setAllowBlanks(true);
    gameManager->getSettingsManager()->setAllowDuplicates(true);
    gameManager->setCode(seq);
    gameManager->setGuess(seq);
    int8_t result = gameManager->makeGuess();

    ASSERT_EQ(result, codes::SUCCESS);
}