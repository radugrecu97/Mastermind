//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_INPUTBLANKS_H
#define MASTERMIND_INPUTBLANKS_H

#include <Menu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class InputBlanks : public Menu {
    public:
        InputBlanks(IController *controller);
    };
}

#endif //MASTERMIND_INPUTBLANKS_H
