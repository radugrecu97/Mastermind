//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_VIEW_H
#define MASTERMIND_VIEW_H

#include <IView.h>
#include <IFrame.h>

class View : public IView {
private:
    std::unique_ptr<IFrame> frame;
public:
    void display(std::pair< IGameState*, IMenu*> data) override;
};

#endif //MASTERMIND_VIEW_H
