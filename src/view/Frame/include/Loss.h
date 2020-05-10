//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_LOSS_H
#define MASTERMIND_LOSS_H

#include <IFrame.h>

namespace frame {

    class Loss : public IFrame {
    public:
        std::string getText() override;
    };
}

#endif //MASTERMIND_LOSS_H
