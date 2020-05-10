//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_MENU_H
#define MASTERMIND_MENU_H

#include <IMenu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class Menu : public IMenu {

    protected:
        uint8_t menuId;
        std::vector<std::unique_ptr<ICommand>> commands;
        IController* controller;

        Menu(IController* controller);
    public:
        int8_t addCommand(uint8_t commandId, uint8_t otherId,  std::string displayText) override;
        int8_t runCommand(ICommand* command, std::string data) override;
        uint8_t getMenuId() override;
        const std::vector<std::unique_ptr<ICommand>>& getCommands() override;
    };

}

#endif //MASTERMIND_MENU_H
