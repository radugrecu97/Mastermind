//
// Created by radugrecu97 on 5/10/20.
//

#include <MakeGuess.h>
#include <status_codes.h>
#include <menu_ids.h>

command::MakeGuess::MakeGuess(uint8_t processData, std::string displayText, IController *controller) : Command(
        processData, displayText, controller) {}

int8_t command::MakeGuess::execute(std::string data) {
    this->controller->setPendingInput(true);
    this->controller->getGameManager()->setGuess(data);
    int8_t statusCode = this->controller->getGameManager()->makeGuess();
    if (statusCode == codes::SUCCESS) {
        // YOU WON
        this->controller->setMenu(menu_ids::VICTORY,0);
        this->controller->setPendingInput(false);
        return codes::SUCCESS;
    } else if (statusCode == codes::FAILURE) {
        // YOU LOST
        this->controller->setMenu(menu_ids::LOSS, 0);
        this->controller->setPendingInput(false);
        return codes::FAILURE;
    }
    return codes::NEUTRAL;
}

