//
// Created by radugrecu97 on 5/10/20.
//

#include <InputMaxTurns.h>
#include <menu_ids.h>
#include <command_ids.h>
#include <setting_ids.h>

menu::InputMaxTurns::InputMaxTurns(IController *controller) : Menu(controller) {
    this->menuId = menu_ids::INPUT_MAX_TURNS;
    uint8_t settingValue = this->controller->getGameManager()->getSettingsManager()->getMaxTurns();
    std::string displayText = "[CHANGE MAX TURNS]\nCURRENT VALUE:" + std::to_string(settingValue) + "\nVALID VALUES: [0 to 255]";
    this->addCommand(command_ids::CHANGE_SETTING, setting_ids::MAX_TURNS, displayText);
}

