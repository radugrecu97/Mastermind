//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_LOSS_H
#define MASTERMIND_LOSS_H

#include <Menu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class Loss : public Menu {
    public:
        Loss(IController *controller);
    };

}


#endif //MASTERMIND_LOSS_H
