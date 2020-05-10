//
// Created by radugrecu97 on 5/10/20.
//

#include <Settings.h>

#include <command_ids.h>
#include <menu_ids.h>
#include <setting_ids.h>

namespace menu {

    Settings::Settings(IController *controller) : Menu(controller) {
        this->menuId = menu_ids::SETTINGS;
        this->addCommand(command_ids::CHANGE_MENU, menu_ids::INPUT_MAX_TURNS, "[MAX TURNS]");
        this->addCommand(command_ids::CHANGE_MENU, menu_ids::INPUT_BLANKS, "[ALLOW BLANKS]");
        this->addCommand(command_ids::CHANGE_MENU, menu_ids::INPUT_DUPLICATES, "[ALLOW DUPLICATES]");
        this->addCommand(command_ids::CHANGE_MENU, menu_ids::INPUT_CODE_PEGS, "[CODE PEG COLORS]");
        this->addCommand(command_ids::CHANGE_MENU, menu_ids::INPUT_KEY_PEGS, "[KEY PEG COLORS]");
    }

}