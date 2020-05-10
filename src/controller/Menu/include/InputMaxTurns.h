//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_INPUTMAXTURNS_H
#define MASTERMIND_INPUTMAXTURNS_H

#include <Menu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class InputMaxTurns : public Menu {
    public:
        InputMaxTurns(IController *controller);
    };

}

#endif //MASTERMIND_INPUTMAXTURNS_H
