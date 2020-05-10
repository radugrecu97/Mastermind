//
// Created by radugrecu97 on 5/10/20.
//

#include <ChangeMenu.h>
#include <menu_ids.h>

namespace command {

    ChangeMenu::ChangeMenu(uint8_t processData, std::string displayText, IController *controller) : Command(processData, displayText, controller) {}

    int8_t ChangeMenu::execute(std::string data) {
        if ((this->processData == menu_ids::INPUT_MAX_TURNS) ||
            (this->processData == menu_ids::INPUT_BLANKS) ||
            (this->processData == menu_ids::INPUT_DUPLICATES) ||
            (this->processData == menu_ids::INPUT_CODE_PEGS) ||
            (this->processData == menu_ids::INPUT_KEY_PEGS) ||
            (this->processData == menu_ids::INPUT_CODE) ||
            (this->processData == menu_ids::GAME))
            this->controller->setPendingInput(true);

        return this->controller->setMenu(this->processData, 0);
    }

}