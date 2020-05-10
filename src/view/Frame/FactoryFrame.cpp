//
// Created by radugrecu97 on 5/10/20.
//

#include <FactoryFrame.h>
#include <menu_ids.h>
#include <Main.h>
#include <Settings.h>

IFrame *FactoryFrame::createFrame(uint8_t menuId) {
    switch (menuId) {
        case (menu_ids::MAIN_MENU):
            return new frame::Main();
        case (menu_ids::SETTINGS):
            return new frame::Settings();


        case (menu_ids::GAME):

        default:
            // input
            return new frame::Settings();
    }
}

