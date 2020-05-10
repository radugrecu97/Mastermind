//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_IFACTORYCOMMAND_H
#define MASTERMIND_IFACTORYCOMMAND_H

#include <bits/unique_ptr.h>
#include <ICommand.h>
#include <IController.h>

class IFactoryCommand {
public:
    virtual ICommand* createCommand(uint8_t commandId, uint8_t otherId, std::string displayText, IController *controller) = 0;
};

#endif //MASTERMIND_IFACTORYCOMMAND_H
