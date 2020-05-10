//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_IFACTORYMENU_H
#define MASTERMIND_IFACTORYMENU_H

#include <bits/unique_ptr.h>
#include <IController.h>
#include "IMenu.h"

class IFactoryMenu {
public:
    virtual IMenu* createMenu(uint8_t commandId, uint8_t otherId, IController* controller) = 0;
};

#endif //MASTERMIND_IFACTORYMENU_H
