//
// Created by radugrecu97 on 5/10/20.
//

#include <Main.h>

#include <FactoryCommand.h>
#include <command_ids.h>
#include <menu_ids.h>

namespace menu {

    Main::Main(IController *controller) {
        this->menuId = menu_ids::MAIN_MENU;
        this->controller = controller;

        std::unique_ptr<IFactoryCommand> factoryCommand = std::make_unique<FactoryCommand>();
        this->commands.push_back(
                std::unique_ptr<ICommand>(factoryCommand->createCommand(command_ids::CHANGE_MENU, menu_ids::GAME, this->controller)));
        this->commands.push_back(
                std::unique_ptr<ICommand>(factoryCommand->createCommand(command_ids::CHANGE_MENU, menu_ids::SETTINGS, this->controller)));
        this->commands.push_back(
                std::unique_ptr<ICommand>(factoryCommand->createCommand(command_ids::QUIT, 0, this->controller)));
    }

    int8_t Main::addCommand(uint8_t commandId, uint8_t otherId) {
        std::unique_ptr<IFactoryCommand> factoryCommand = std::make_unique<FactoryCommand>();
        this->commands.push_back(std::unique_ptr<ICommand>(factoryCommand->createCommand(commandId, otherId, this->controller)));
        return 0;
    }

    int8_t Main::runCommand(ICommand *command, std::string data) {
        return command->execute(data);
    }

    uint8_t Main::getMenuId() {
        return this->menuId;
    }

    const std::vector<std::unique_ptr<ICommand>>& Main::getCommands() {
        return this->commands;
    }

}