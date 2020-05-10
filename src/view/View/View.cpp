//
// Created by radugrecu97 on 5/10/20.
//
#include <View.h>
#include <FactoryFrame.h>
#include <iostream>
#include <menu_ids.h>

void View::display(std::pair< IGameState*, IMenu*> data) {
    std::unique_ptr<IFactoryFrame> factoryFrame(std::make_unique<FactoryFrame>());
    std::string text = factoryFrame->createFrame(data.second->getMenuId())->getText();
    text.append("\n\n");

    if (data.second->getMenuId() == menu_ids::GAME) {
        text.append("[ DEFAULT COLOR SEQUENCE = ROYGBI]\n");
        text.append("[TURN HISTORY]\n");
        for (int i = data.first->getTurnCount()-1; i>=0; i--) {
            text.append(std::to_string(i+1) + ". " + data.first->getHistory()[i] + "\n");
        }
    }

    text.append("\n\n");


    const std::vector<std::unique_ptr<ICommand>> &commands = data.second->getCommands();
    for (int i=0; i<commands.size(); i++) {
        text.append(std::to_string(i+1) + ". " + commands[i].get()->getDisplayText() + "     ");
    }
    std::cout << text << std::endl;
}