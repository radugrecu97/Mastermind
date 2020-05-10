//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_VICTORY_H
#define MASTERMIND_VICTORY_H

#include <IFrame.h>

namespace frame {

    class Victory : public IFrame {
    public:
        std::string getText() override;
    };
}

#endif //MASTERMIND_VICTORY_H
