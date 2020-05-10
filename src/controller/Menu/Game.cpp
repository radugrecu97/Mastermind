//
// Created by radugrecu97 on 5/10/20.
//

#include <Game.h>
#include <command_ids.h>
#include <menu_ids.h>

namespace menu {

    Game::Game(IController *controller) : Menu(controller) {
        this->menuId = menu_ids::GAME;
        this->addCommand(command_ids::MAKE_GUESS, 0, "[WRITE YOUR GUESS AND PRESS ENTER]");
    }

}