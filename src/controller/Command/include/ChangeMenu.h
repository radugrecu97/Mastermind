//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_CHANGEMENU_H
#define MASTERMIND_CHANGEMENU_H

#include <Command.h>
#include <IController.h>
#include <bits/unique_ptr.h>

namespace command {
    class ChangeMenu : public Command {
    public:
        ChangeMenu(uint8_t processData, std::string displayText, IController *controller);
        int8_t execute(std::string data) override;
    };
}


#endif //MASTERMIND_CHANGEMENU_H
