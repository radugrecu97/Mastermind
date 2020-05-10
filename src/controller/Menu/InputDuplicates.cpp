//
// Created by radugrecu97 on 5/10/20.
//

#include <InputDuplicates.h>
#include <menu_ids.h>
#include <command_ids.h>
#include <setting_ids.h>

menu::InputDuplicates::InputDuplicates(IController *controller) : Menu(controller) {
    this->menuId = menu_ids::INPUT_DUPLICATES;;
    std::string settingValue;
    if  (this->controller->getGameManager()->getSettingsManager()->getAllowDuplicates())
        settingValue = "y";
    else
        settingValue = "n";
    std::string displayText = "[ALLOW DUPLICATES?]\nCURRENT VALUE:" + settingValue + "\nVALID VALUES: [ y or n ]";
    this->addCommand(command_ids::CHANGE_SETTING, setting_ids::DUPLICATES, displayText);

}

