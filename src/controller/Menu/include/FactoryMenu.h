//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_FACTORYMENU_H
#define MASTERMIND_FACTORYMENU_H

#include <IFactoryMenu.h>

class FactoryMenu: public IFactoryMenu {
public:
    FactoryMenu();
    IMenu* createMenu(uint8_t commandId, uint8_t otherId, IController* controller) override;
};

#endif //MASTERMIND_FACTORYMENU_H
