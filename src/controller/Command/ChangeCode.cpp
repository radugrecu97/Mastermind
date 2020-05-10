//
// Created by radugrecu97 on 5/10/20.
//

#include <ChangeCode.h>
#include <menu_ids.h>

command::ChangeCode::ChangeCode(uint8_t processData, std::string displayText, IController *controller) : Command(
        processData, displayText, controller) {

}

int8_t command::ChangeCode::execute(std::string data) {
    int8_t statusCode = this->controller->getGameManager()->setCode(data);
    this->controller->setMenu(menu_ids::SETTINGS, 0);
    return statusCode;
}

