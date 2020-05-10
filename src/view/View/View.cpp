//
// Created by radugrecu97 on 5/10/20.
//
#include <View.h>
#include <FactoryFrame.h>
#include <iostream>

void View::display(std::pair< IGameState*, IMenu*> data) {
    std::unique_ptr<IFactoryFrame> factoryFrame(std::make_unique<FactoryFrame>());
    std::string text = factoryFrame->createFrame(data.second->getMenuId())->getText();
    text.append("\n\n\n");

    const std::vector<std::unique_ptr<ICommand>> &commands = data.second->getCommands();
    for (int i=0; i<commands.size(); i++) {
        text.append(std::to_string(i+1) + ". " + commands[i].get()->getDisplayText() + "     ");
    }
    std::cout << text << std::endl;
}