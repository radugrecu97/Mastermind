//
// Created by radugrecu97 on 5/10/20.
//

#include <Controller.h>
#include <Main.h>

#include <memory>
#include <GameManager.h>
#include <Util.h>
#include <status_codes.h>
#include <FactoryMenu.h>
#include <View.h>

Controller::Controller() {
    this->pendingInput = false;
    this->menu = std::make_unique<menu::Main>(this);
    this->gameManager = std::make_unique<GameManager>();
    this->view = std::make_unique<View>();
}

int8_t Controller::handleInput(std::string input) {
    int8_t statusCode;
    if (this->pendingInput) {
        pendingInput = false;
        statusCode = this->menu->runCommand(this->menu->getCommands()[0].get(), input);
    } else {
        std::unique_ptr<IUtil> util = std::make_unique<Util>();
        if (util->validateNumbers(input) == codes::SUCCESS) {
            // only digits in string
            int8_t index = std::stoi(input);
            try {
                statusCode = this->menu->runCommand(this->menu->getCommands()[index-1].get(), "");
            } catch (const std::exception& e) {}
        }
    }
    this->view->display(std::make_pair(this->gameManager->getGameState(), this->menu.get()));
    return statusCode;
}

int8_t Controller::setMenu(uint8_t menuId, uint8_t otherId) {
    std::unique_ptr<IFactoryMenu> factoryMenu = std::make_unique<FactoryMenu>();
    this->menu.reset(factoryMenu->createMenu(menuId, otherId, this));
    return 0;
}

void Controller::setPendingInput(bool state) {
    this->pendingInput = state;
}

void Controller::updateView() {
    this->view->display(std::make_pair(this->gameManager->getGameState(), this->menu.get()));
}

int8_t Controller::changeSetting(uint8_t settingId, std::string value) {
    return this->gameManager->changeSetting(settingId, value);
}

IGameManager *Controller::getGameManager() {
    return this->gameManager.get();
}
