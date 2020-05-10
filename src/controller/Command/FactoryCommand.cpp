//
// Created by radugrecu97 on 5/10/20.
//

#include <FactoryCommand.h>
#include <command_ids.h>
#include <setting_ids.h>
#include <ChangeMenu.h>
#include <ChangeSetting.h>

ICommand* FactoryCommand::createCommand(uint8_t commandId, uint8_t otherId, std::string displayText, IController *controller) {
    switch (commandId) {
        case (command_ids::CHANGE_MENU):
            return new command::ChangeMenu(otherId, displayText, controller);
        case (command_ids::CHANGE_SETTING):
            return new command::ChangeSetting(otherId, displayText, controller);
        case (command_ids::QUIT):

        case (command_ids::MAKE_GUESS):

        default:
            return nullptr;
    }
}
