//
// Created by radugrecu97 on 5/10/20.
//

#include <Command.h>

#include <utility>

command::Command::Command(uint8_t newMenuId, std::string displayText, IController *controller) {
    this->processData = newMenuId;
    this->controller.reset(controller);
    this->displayText = std::move(displayText);
}

std::string command::Command::getDisplayText() {
    return this->displayText;
}

