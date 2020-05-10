//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_VICTORY_H
#define MASTERMIND_VICTORY_H

#include <Menu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class Victory : public Menu {
    public:
        Victory(IController *controller);
    };

}


#endif //MASTERMIND_VICTORY_H
