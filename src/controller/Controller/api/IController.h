//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_ICONTROLLER_H
#define MASTERMIND_ICONTROLLER_H

#include <IGameState.h>
#include <IMenu.h>
#include <IGameManager.h>

class IController {
public:
    virtual int8_t handleInput(std::string input) = 0;
    virtual int8_t setMenu(uint8_t menuId, uint8_t otherId) = 0;
    virtual void setPendingInput(bool state) = 0;
    virtual void updateView() = 0;
    virtual int8_t changeSetting(uint8_t settingId, std::string value) = 0;
    virtual IGameManager* getGameManager() = 0;
};

#endif //MASTERMIND_ICONTROLLER_H
