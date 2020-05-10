//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_INPUTCODEPEGS_H
#define MASTERMIND_INPUTCODEPEGS_H

#include <Menu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class InputCodePegs : public Menu {
    public:
        InputCodePegs(IController *controller);
    };
}

#endif //MASTERMIND_INPUTCODEPEGS_H
