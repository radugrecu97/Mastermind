//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_GAME_H
#define MASTERMIND_GAME_H

#include <Menu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class Game : public Menu {
    public:
        Game(IController *controller);
    };

}

#endif //MASTERMIND_GAME_H
