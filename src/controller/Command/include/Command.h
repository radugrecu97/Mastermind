//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_COMMAND_H
#define MASTERMIND_COMMAND_H

#include <ICommand.h>
#include <IController.h>
#include <bits/unique_ptr.h>

namespace command {
    class Command: public ICommand {
    protected:
        uint8_t processData;
        std::string displayText;
        std::unique_ptr<IController> controller;

        Command(uint8_t processData,  std::string displayText, IController *controller);
    public:
        virtual int8_t execute(std::string data) = 0;
        std::string getDisplayText();
    };
}

#endif //MASTERMIND_COMMAND_H
