//
// Created by radugrecu97 on 5/10/20.
//

#include <InputCodePegs.h>
#include <menu_ids.h>
#include <command_ids.h>
#include <setting_ids.h>

menu::InputCodePegs::InputCodePegs(IController *controller) : Menu(controller) {
    this->menuId = menu_ids::INPUT_CODE_PEGS;
    std::string settingValue;
    for (auto c : this->controller->getGameManager()->getPegManager()->getCodePegs())
    {
        settingValue.append(c);
    }

    std::string displayText = "[CODE PEG COLORS]\nCURRENT VALUE:" + settingValue + "\nVALID VALUES: [ 6 letter long uppercase, unique sequence - ABCDEF ]";
    this->addCommand(command_ids::CHANGE_SETTING, setting_ids::CODE_PEG_COLOR, displayText);
}

