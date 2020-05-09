//
// Created by radugrecu97 on 5/6/20.
//

#include "gtest/gtest.h"
#include <IPegManager.h>
#include <PegManager.h>
#include <IUtil.h>
#include <Util.h>
#include <ISettingsManager.h>
#include <SettingsManager.h>

// ************************************ Util ************************************

// validateUpperLetters
TEST(UtilTestSuite, VALIDATE_UPPER_LETTERS_SUCCESS) {
    // init
    IUtil *util = new Util();

    int8_t result = util->validateUpperLetters("A");
    ASSERT_EQ(result, 1);
}

TEST(UtilTestSuite, VALIDATE_UPPER_LETTERS_FAIL) {
    // init
    IUtil *util = new Util();

    int8_t result = util->validateUpperLetters("*");
    ASSERT_EQ(result, -1);
}

// ************************************ PegManager ************************************

// setCodePegs

TEST(PegManagerTestSuite, SET_CODE_PEGS_SUCCESS) {
    // init
    IPegManager *pegManager = new PegManager();
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "I"};

    int8_t result = pegManager->setCodePegs(colorSet);
    ASSERT_EQ(result, 1);
}

TEST(PegManagerTestSuite, SET_CODE_PEGS_FAIL_SIZE) {
    // init
    IPegManager *pegManager = new PegManager();
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "B"};

    int8_t result = pegManager->setCodePegs(colorSet);
    ASSERT_EQ(result, -1);
}

TEST(PegManagerTestSuite, SET_CODE_PEGS_FAIL_INVALID) {
    // init
    IPegManager *pegManager = new PegManager();
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "*"};

    int8_t result = pegManager->setCodePegs(colorSet);
    ASSERT_EQ(result, 0);
}

// setKeyPegColor

TEST(PegManagerTestSuite, SET_KEY_PEG_COLOR_SUCCESS) {
    // init
    IPegManager *pegManager = new PegManager();
    std::string keyPegColor = "W";
    std::string keyPegPosition = "B";
    pegManager->setKeyPegPosition(keyPegPosition);

    int8_t result = pegManager->setKeyPegColor(keyPegColor);
    ASSERT_EQ(result, 1);
}

TEST(PegManagerTestSuite, SET_KEY_PEG_COLOR_INVALID) {
    // init
    IPegManager *pegManager = new PegManager();
    std::string keyPegColor = "*";
    std::string keyPegPosition = "B";
    pegManager->setKeyPegPosition(keyPegPosition);

    int8_t result = pegManager->setKeyPegColor(keyPegColor);
    ASSERT_EQ(result, -1);
}

TEST(PegManagerTestSuite, SET_KEY_PEG_COLOR_TAKEN) {
    // init
    IPegManager *pegManager = new PegManager();
    std::string keyPegColor = "W";
    std::string keyPegPosition = "W";
    pegManager->setKeyPegPosition(keyPegPosition);

    int8_t result = pegManager->setKeyPegColor(keyPegColor);
    ASSERT_EQ(result, 0);
}

// setKeyPegPosition

TEST(PegManagerTestSuite, SET_KEY_PEG_POSITION_SUCCESS) {
    // init
    IPegManager *pegManager = new PegManager();
    std::string keyPegColor = "W";
    std::string keyPegPosition = "B";
    pegManager->setKeyPegColor(keyPegColor);

    int8_t result = pegManager->setKeyPegPosition(keyPegPosition);
    ASSERT_EQ(result, 1);
}

TEST(PegManagerTestSuite, SET_KEY_PEG_POSITION_INVALID) {
    // init
    IPegManager *pegManager = new PegManager();
    std::string keyPegColor = "W";
    std::string keyPegPosition = "*";
    pegManager->setKeyPegColor(keyPegColor);

    int8_t result = pegManager->setKeyPegPosition(keyPegPosition);
    ASSERT_EQ(result, -1);
}

TEST(PegManagerTestSuite, SET_KEY_PEG_POSITION_TAKEN) {
    // init
    IPegManager *pegManager = new PegManager();
    std::string keyPegColor = "W";
    std::string keyPegPosition = "W";
    pegManager->setKeyPegColor(keyPegColor);

    int8_t result = pegManager->setKeyPegPosition(keyPegPosition);
    ASSERT_EQ(result, 0);
}

// replaceCodePeg

TEST(PegManagerTestSuite, REPLACE_CODE_PEG_COLOR_SUCCESS) {
    // init
    IPegManager *pegManager = new PegManager();
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "I"};
    pegManager->setCodePegs(colorSet);

    int8_t result = pegManager->replaceCodePeg("R",  "C");
    ASSERT_EQ(result, 1);
}

TEST(PegManagerTestSuite, REPLACE_CODE_PEG_COLOR_FAIL_OLD) {
    // init
    IPegManager *pegManager = new PegManager();
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "I"};
    pegManager->setCodePegs(colorSet);

    int8_t result = pegManager->replaceCodePeg("Z",  "C");
    ASSERT_EQ(result, -1);
}

TEST(PegManagerTestSuite, REPLACE_CODE_PEG_COLOR_FAIL_NEW) {
    // init
    IPegManager *pegManager = new PegManager();
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "I"};
    pegManager->setCodePegs(colorSet);

    int8_t result = pegManager->replaceCodePeg("R",  "Y");
    ASSERT_EQ(result, 0);
}

// getters

TEST(PegManagerTestSuite, GET_CODE_PEGS) {
    // init
    IPegManager *pegManager = new PegManager();
    std::set<std::string> colorSet { "R", "O", "Y", "G", "B", "I"};
    pegManager->setCodePegs(colorSet);

    bool result = pegManager->getCodePegs() == colorSet;
    ASSERT_EQ(result, true);
}

TEST(PegManagerTestSuite, GET_KEY_COLOR) {
    // init
    IPegManager *pegManager = new PegManager();
    std::string keyPegColor = "W";
    pegManager->setKeyPegColor(keyPegColor);

    bool result = pegManager->getKeyPegColor() == keyPegColor;
    ASSERT_EQ(result, true);
}

TEST(PegManagerTestSuite, GET_KEY_POSITION) {
    // init
    IPegManager *pegManager = new PegManager();
    std::string keyPegPosition = "B";
    pegManager->setKeyPegPosition(keyPegPosition);

    bool result = pegManager->getKeyPegPosition() == keyPegPosition;
    ASSERT_EQ(result, true);
}

// ************************************ SettingsManager ************************************

TEST(SettingsManagerTestSuite, SET_MAX_TURNS) {
    // init
    ISettingsManager *settingsManager = new SettingsManager();
    int8_t count = 8;
    settingsManager->setMaxTurns(count);

    bool result = count && settingsManager->getMaxTurns();
    ASSERT_EQ(result, true);
}

TEST(SettingsManagerTestSuite, SET_ALLOW_BLANKS) {
    // init
    ISettingsManager *settingsManager = new SettingsManager();
    int8_t state = true;
    settingsManager->setAllowBlanks(state);

    bool result = state && settingsManager->getAllowBlanks();
    ASSERT_EQ(result, true);
}

TEST(SettingsManagerTestSuite, SET_ALLOW_DUPLICATES) {
    // init
    ISettingsManager *settingsManager = new SettingsManager();
    int8_t state = true;
    settingsManager->setAllowDuplicates(state);

    bool result = state && settingsManager->getAllowDuplicates();
    ASSERT_EQ(result, true);
}