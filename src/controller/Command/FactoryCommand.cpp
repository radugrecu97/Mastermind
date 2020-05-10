//
// Created by radugrecu97 on 5/10/20.
//

#include <FactoryCommand.h>
#include <command_ids.h>
#include <ChangeMenu.h>

ICommand* FactoryCommand::createCommand(uint8_t commandId, uint8_t otherId, IController *controller) {
    switch (commandId) {
        case (command_ids::CHANGE_MENU):
            return new command::ChangeMenu(otherId, controller);
        case (command_ids::CHANGE_SETTING):

        case (command_ids::QUIT):

        case (command_ids::MAKE_GUESS):

        default:
            return nullptr;
    }
}
