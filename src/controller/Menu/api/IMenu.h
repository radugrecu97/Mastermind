//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_IMENU_H
#define MASTERMIND_IMENU_H

#include <ICommand.h>
#include <vector>
#include <bits/unique_ptr.h>

class IMenu {
public:
    virtual int8_t addCommand(uint8_t commandId, uint8_t otherId, std::string displayText) = 0;
    virtual int8_t runCommand(ICommand* command, std::string data) = 0;
    virtual uint8_t getMenuId() = 0;
    virtual const std::vector<std::unique_ptr<ICommand>>& getCommands() = 0;
};

#endif //MASTERMIND_IMENU_H
