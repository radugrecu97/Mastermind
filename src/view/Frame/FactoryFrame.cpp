//
// Created by radugrecu97 on 5/10/20.
//

#include <FactoryFrame.h>
#include <menu_ids.h>
#include <Main.h>
#include <Settings.h>
#include <Game.h>
#include <Victory.h>
#include <Loss.h>

IFrame *FactoryFrame::createFrame(uint8_t menuId) {
    switch (menuId) {
        case (menu_ids::MAIN_MENU):
            return new frame::Main();
        case (menu_ids::SETTINGS):
            return new frame::Settings();
        case (menu_ids::GAME):
            return new frame::Game();
        case (menu_ids::LOSS):
            return new frame::Loss();
        case (menu_ids::VICTORY):
            return new frame::Victory();
        default:
            // input
            return new frame::Settings();
    }
}

