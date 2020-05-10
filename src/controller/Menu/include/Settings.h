//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_SETTINGS_H
#define MASTERMIND_SETTINGS_H

#include <Menu.h>
#include <bits/unique_ptr.h>
#include <IController.h>

namespace menu {

    class Settings : public Menu {
    public:
        Settings(IController *controller);
    };

}

#endif //MASTERMIND_SETTINGS_H
