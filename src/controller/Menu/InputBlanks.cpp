//
// Created by radugrecu97 on 5/10/20.
//

#include <InputBlanks.h>
#include <menu_ids.h>
#include <command_ids.h>
#include <setting_ids.h>

menu::InputBlanks::InputBlanks(IController *controller) : Menu(controller) {
    this->menuId = menu_ids::INPUT_BLANKS;
    std::string settingValue;
    if  (this->controller->getGameManager()->getSettingsManager()->getAllowBlanks())
        settingValue = "y";
    else
        settingValue = "n";
    std::string displayText = "[ALLOW BLANKS?]\nCURRENT VALUE:" + settingValue + "\nVALID VALUES: [ y or n ]";
    this->addCommand(command_ids::CHANGE_SETTING, setting_ids::BLANKS, displayText);
}

