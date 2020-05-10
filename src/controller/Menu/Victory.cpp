//
// Created by radugrecu97 on 5/10/20.
//

#include <Victory.h>
#include <command_ids.h>
#include <menu_ids.h>

namespace menu {

    Victory::Victory(IController *controller) : Menu(controller) {
        this->menuId = menu_ids::VICTORY;
        this->addCommand(command_ids::CHANGE_MENU, menu_ids::MAIN_MENU, "[MAIN MENU]");
        this->addCommand(command_ids::CHANGE_MENU, menu_ids::SETTINGS, "[SETTINGS]");
    }
}