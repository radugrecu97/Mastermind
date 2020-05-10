//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_ICONTROLLER_H
#define MASTERMIND_ICONTROLLER_H

#include <IGameState.h>

class IController {
public:
    virtual IGameState* handleInput(std::string input) = 0;
    virtual int8_t setMenu(uint8_t menuId, uint8_t otherId) = 0;
    virtual void setPendingInput(bool state) = 0;
};

#endif //MASTERMIND_ICONTROLLER_H
