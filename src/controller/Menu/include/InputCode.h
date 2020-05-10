//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_INPUTCODE_H
#define MASTERMIND_INPUTCODE_H

#include <Menu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class InputCode : public Menu {
    public:
        InputCode(IController *controller);
    };
}

#endif //MASTERMIND_INPUTCODE_H
