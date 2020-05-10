//
// Created by radugrecu97 on 5/10/20.
//

#include <Main.h>
#include <command_ids.h>
#include <menu_ids.h>

namespace menu {

    Main::Main(IController *controller) : Menu(controller) {
        this->menuId = menu_ids::MAIN_MENU;
        this->addCommand(command_ids::CHANGE_MENU, menu_ids::GAME, "[NEW GAME]");
        this->addCommand(command_ids::CHANGE_MENU, menu_ids::SETTINGS, "[SETTINGS]");
        //this->addCommand(command_ids::CHANGE_MENU, menu_ids::GAME, "[NEW GAME]");
    }


}