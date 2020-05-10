//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_INPUTKEYPEGS_H
#define MASTERMIND_INPUTKEYPEGS_H

#include <Menu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class InputKeyPegs : public Menu {
    public:
        InputKeyPegs(IController *controller);
    };
}

#endif //MASTERMIND_INPUTKEYPEGS_H
