//
// Created by radugrecu97 on 5/10/20.
//

#include <Controller.h>
#include <Main.h>

#include <memory>
#include <GameManager.h>
#include <Util.h>
#include <error_codes.h>
#include <FactoryMenu.h>

Controller::Controller() {
    this->pendingInput = false;
    this->menu = std::make_unique<menu::Main>(this);
    this->gameManager = std::make_unique<GameManager>();
}

IGameState *Controller::handleInput(std::string input) {
    if (this->pendingInput) {
        this->menu->runCommand(this->menu->getCommands()[0].get(), input);
    } else {
        std::unique_ptr<IUtil> util = std::make_unique<Util>();
        if (util->validateNumbers(input) == codes::SUCCESS) {
            // only digits in string
            int8_t index = std::stoi(input);
            try {
                this->menu->runCommand(this->menu->getCommands()[index].get(), "");
            } catch (const std::exception& e) {}
        }

    }
    return this->gameManager->getGameState();
}

int8_t Controller::setMenu(uint8_t menuId, uint8_t otherId) {
    std::unique_ptr<IFactoryMenu> factoryMenu = std::make_unique<FactoryMenu>();
    this->menu.reset(factoryMenu->createMenu(menuId, otherId, this));
    return 0;
}

void Controller::setPendingInput(bool state) {
    this->pendingInput = state;
}


