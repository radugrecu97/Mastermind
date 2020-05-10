//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_FACTORYCOMMAND_H
#define MASTERMIND_FACTORYCOMMAND_H

#include <IFactoryCommand.h>

class FactoryCommand: public IFactoryCommand {
public:
    ICommand* createCommand(uint8_t commandId, uint8_t otherId, std::string displayText, IController *controller) override;
};

#endif //MASTERMIND_FACTORYCOMMAND_H
