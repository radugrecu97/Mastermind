//
// Created by radugrecu97 on 5/10/20.
//

#include <Menu.h>

#include <FactoryCommand.h>
#include <command_ids.h>

namespace menu {

    Menu::Menu(IController *controller) {
        this->controller = controller;
    }

    int8_t Menu::addCommand(uint8_t commandId, uint8_t otherId, std::string displayText) {
        std::unique_ptr<IFactoryCommand> factoryCommand = std::make_unique<FactoryCommand>();
        this->commands.push_back(std::unique_ptr<ICommand>(
                factoryCommand->createCommand(commandId, otherId, displayText, this->controller)));
        return 0;
    }

    int8_t Menu::runCommand(ICommand *command, std::string data) {
        return command->execute(data);
    }

    uint8_t Menu::getMenuId() {
        return this->menuId;
    }

    const std::vector<std::unique_ptr<ICommand>> &Menu::getCommands() {
        return this->commands;
    }
}