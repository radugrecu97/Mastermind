//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_IVIEW_H
#define MASTERMIND_IVIEW_H

#include <IGameState.h>
#include <IMenu.h>
#include <bits/unique_ptr.h>

class IView {
public:
    virtual void display(std::pair< IGameState*, IMenu*> data) = 0;
};

#endif //MASTERMIND_IVIEW_H
