//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_GAME_H
#define MASTERMIND_GAME_H

#include <IFrame.h>

namespace frame {

    class Game : public IFrame {
    public:
        std::string getText() override;
    };
}

#endif //MASTERMIND_GAME_H
