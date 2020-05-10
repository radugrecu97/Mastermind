//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_CHANGEMENU_H
#define MASTERMIND_CHANGEMENU_H

#include <ICommand.h>
#include <IController.h>
#include <bits/unique_ptr.h>

namespace command {
    class ChangeMenu : public ICommand {
    private:
        uint8_t newMenuId;
        std::unique_ptr<IController> controller;
    public:
        ChangeMenu(uint8_t newMenuId,  IController *controller);
        int8_t execute(std::string data) override;
    };
}


#endif //MASTERMIND_CHANGEMENU_H
