//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_INPUTDUPLICATES_H
#define MASTERMIND_INPUTDUPLICATES_H

#include <Menu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class InputDuplicates : public Menu {
    public:
        InputDuplicates(IController *controller);
    };
}

#endif //MASTERMIND_INPUTDUPLICATES_H
