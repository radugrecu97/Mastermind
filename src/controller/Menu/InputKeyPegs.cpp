//
// Created by radugrecu97 on 5/10/20.
//

#include <InputKeyPegs.h>
#include <menu_ids.h>
#include <command_ids.h>
#include <setting_ids.h>

menu::InputKeyPegs::InputKeyPegs(IController *controller) : Menu(controller) {
    this->menuId = menu_ids::INPUT_KEY_PEGS;
    std::string settingValue = this->controller->getGameManager()->getPegManager()->getKeyPegColor() + this->controller->getGameManager()->getPegManager()->getKeyPegPosition();
    std::string displayText = "[CHANGE KEY PEG COLORS ( PRESENT, EXACT )]\nCURRENT VALUE:" + settingValue + "\nVALID VALUES: [ 2 letter-long, uppercase, unique sequence - RW ]";
    this->addCommand(command_ids::CHANGE_SETTING, setting_ids::KEY_PEG_COLOR, displayText);
}

