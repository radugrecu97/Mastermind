//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_MAKEGUESS_H
#define MASTERMIND_MAKEGUESS_H

#include <Command.h>
#include <IController.h>
#include <bits/unique_ptr.h>

namespace command {
    class MakeGuess : public Command {
    public:
        MakeGuess(uint8_t processData, std::string displayText, IController *controller);
        int8_t execute(std::string data) override;
    };
}


#endif //MASTERMIND_MAKEGUESS_H
