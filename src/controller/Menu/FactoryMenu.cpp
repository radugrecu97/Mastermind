//
// Created by radugrecu97 on 5/10/20.
//

#include <FactoryMenu.h>
#include "menu_ids.h"
#include <Main.h>

FactoryMenu::FactoryMenu() = default;

IMenu* FactoryMenu::createMenu(uint8_t commandId, uint8_t otherId, IController *controller) {
    switch (commandId) {
        case (menu_ids::MAIN_MENU):
            return new menu::Main(controller);
        case (menu_ids::SETTINGS):

        case (menu_ids::INPUT):

        case (menu_ids::GAME):

        default:
            return nullptr;
    }
}


