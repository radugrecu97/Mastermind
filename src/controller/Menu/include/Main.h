//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_MAIN_H
#define MASTERMIND_MAIN_H

#include <IMenu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class Main : public IMenu {
    private:
        uint8_t menuId;
        std::vector<std::unique_ptr<ICommand>> commands;
        IController* controller;
    public:
        explicit Main(IController* controller);
        int8_t addCommand(uint8_t commandId, uint8_t otherId) override;
        int8_t runCommand(ICommand* command, std::string data) override;
        uint8_t getMenuId() override;
        const std::vector<std::unique_ptr<ICommand>>& getCommands() override;
    };

}

#endif //MASTERMIND_MAIN_H
