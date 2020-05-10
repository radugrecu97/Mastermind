//
// Created by radugrecu97 on 5/10/20.
//

#include <InputCode.h>
#include <menu_ids.h>
#include <command_ids.h>
#include <setting_ids.h>

menu::InputCode::InputCode(IController *controller) : Menu(controller) {
    this->menuId = menu_ids::INPUT_CODE;
    std::string settingValue = this->controller->getGameManager()->getGameState()->getCode();
    std::string displayText = "[CHANGE CODE]\nCURRENT VALUE:" + settingValue + "\nVALID VALUES: [ 6 letter-long, uppercase, unique sequence. Blanks and duplicates are allowed depending on setting - ABCDEF ]";
    this->addCommand(command_ids::CHANGE_CODE, 0, displayText);
}