//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_MAIN_H
#define MASTERMIND_MAIN_H

#include <Menu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class Main : public Menu {
    public:
        Main(IController *controller);
    };

}

#endif //MASTERMIND_MAIN_H
