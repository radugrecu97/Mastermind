//
// Created by radugrecu97 on 5/10/20.
//

#include <ChangeMenu.h>
#include <menu_ids.h>

namespace command {

    ChangeMenu::ChangeMenu(uint8_t newMenuId, IController *controller) {
        this->newMenuId = newMenuId;
        this->controller.reset(controller);
    }

    int8_t ChangeMenu::execute(std::string data) {
        return this->controller->setMenu(this->newMenuId, 0);
    }

}