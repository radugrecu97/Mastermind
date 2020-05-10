//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_CONTROLLER_H
#define MASTERMIND_CONTROLLER_H

#include <IGameState.h>
#include <IController.h>
#include <IMenu.h>
#include <IGameManager.h>
#include <IView.h>
#include <bits/unique_ptr.h>

class Controller : public IController {
private:
    bool pendingInput;
    std::unique_ptr<IMenu> menu;
    std::unique_ptr<IGameManager> gameManager;
    std::unique_ptr<IView> view;
public:
    Controller();
    int8_t handleInput(std::string input) override;
    int8_t setMenu(uint8_t menuId, uint8_t otherId) override;
    void setPendingInput(bool state) override;
    void updateView() override;
    int8_t changeSetting(uint8_t settingId, std::string value) override;
    IGameManager* getGameManager() override ;
};


#endif //MASTERMIND_CONTROLLER_H
