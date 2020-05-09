//
// Created by radugrecu97 on 5/6/20.
//

#include "gtest/gtest.h"
#include <IPeg.h>
#include <Peg.h>


TEST(PegTestSuite, NEW_CODE_PEG) {
    IPeg *peg = new Peg("Red");
    ASSERT_EQ(peg->getColor(), "Red");
}

TEST(PegTestSuite, SET_CODE_PEG_COLOR) {
    IPeg *peg = new Peg("Red");
    peg->setColor("Blue");
    ASSERT_EQ(peg->getColor(), "Blue");
}

//
//TEST(PegTestSuite, GET_CODE_PEGS{
//    IPegManager *pegManager = new PegManager();
//    std::set<IPeg> = pegManager.getCodePegs();
//}
//
//TEST(MenuTestSuite, SET_ACTIONS_SETTINGS_MENU{
//    IActions *actionsMenu = ActionsFactory("Settings");
//    IMenu *settingsMenu  = new Menu(actionsMenu);
//}
//
//TEST(MenuTestSuite, SET_SETTINGS_MENU{
//    IMenu *settingsMenu = MenuFactory("Settings");
//    IFrame *frame = new Frame(menu);
//}
//
//TEST(InputTestSuite, PROCESS_INPUT) {
//    IMenu *settingsMenu = MenuFactory("Settings");
//    IFrame *frame = new Frame(menu);
//    frame.processInput("3");
//}
//
//TEST(ActionTestSuite, EXECUTE_ACTION) {
//    IMenu *settingsMenu = MenuFactory("Settings");
//    settingsMenu.performAction("3");
//}
//
//TEST(ActionTestSuite, CHANGE_COLOR) {
//    actions::IAction *changeColor = FactoryAction.getAction("peg_color");
//
//    changeColor.execute("B");
//
//
//}
//
//TEST(ActionTestSuite, CHANGE_MENU) {
//    actions::IAction *changeMenu = FactoryAction.getAction("menu");
//    changeColor.execute("B");
//}
//
//TEST(ActionTestSuite, CHANGE_SETTING) {
//    actions::IAction *changeSetting = FactoryAction.getAction("setting");
//    changeColor.execute("B");
//}
//
//TEST(ActionTestSuite, INITIALIZE_MENU) {
//    std::vector<*IAction> actions;
//    temp = FactoryAction.getAction("menu");
//    temp.set
//    actions.add();
//    actions.add(FactoryAction.getAction("setting"));
//
//    IMenu menu = new Menu
//}

