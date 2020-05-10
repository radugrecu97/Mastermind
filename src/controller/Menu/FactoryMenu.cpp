//
// Created by radugrecu97 on 5/10/20.
//

#include <FactoryMenu.h>
#include "menu_ids.h"
#include <Main.h>
#include <Settings.h>
#include <InputMaxTurns.h>
#include <InputBlanks.h>
#include <InputDuplicates.h>
#include <InputCodePegs.h>
#include <InputKeyPegs.h>
#include <InputCode.h>
#include <Game.h>
#include <Victory.h>
#include <Loss.h>

FactoryMenu::FactoryMenu() = default;

IMenu* FactoryMenu::createMenu(uint8_t commandId, uint8_t otherId, IController *controller) {
    switch (commandId) {
        case (menu_ids::MAIN_MENU):
            return new menu::Main(controller);
        case (menu_ids::SETTINGS):
            return new menu::Settings(controller);
        case (menu_ids::INPUT_MAX_TURNS):
            return new menu::InputMaxTurns(controller);
        case (menu_ids::INPUT_BLANKS):
            return new menu::InputBlanks(controller);
        case (menu_ids::INPUT_DUPLICATES):
            return new menu::InputDuplicates(controller);
        case (menu_ids::INPUT_CODE_PEGS):
            return new menu::InputCodePegs(controller);
        case (menu_ids::INPUT_KEY_PEGS):
            return new menu::InputKeyPegs(controller);
        case (menu_ids::INPUT_CODE):
            return new menu::InputCode(controller);
        case (menu_ids::VICTORY):
            return new menu::Victory(controller);
        case (menu_ids::LOSS):
            return new menu::Loss(controller);
        case (menu_ids::GAME):
            return new menu::Game(controller);
        default:
            return nullptr;
    }
}


