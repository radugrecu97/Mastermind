//
// Created by radugrecu97 on 5/10/20.
//

#include <ChangeSetting.h>
#include <menu_ids.h>
#include <status_codes.h>
namespace command {

    ChangeSetting::ChangeSetting(uint8_t processData, std::string displayText, IController *controller) : Command(processData, displayText, controller) {}

    int8_t ChangeSetting::execute(std::string data) {
        int8_t statusCode = this->controller->changeSetting(this->processData, data);
        this->controller->setMenu(menu_ids::SETTINGS, 0);
        return statusCode;
    }

}