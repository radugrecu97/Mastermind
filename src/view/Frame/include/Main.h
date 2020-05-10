//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_MAIN_H
#define MASTERMIND_MAIN_H

#include <IFrame.h>

namespace frame {

    class Main : public IFrame {
    public:
        std::string getText() override;
    };
}

#endif //MASTERMIND_MAIN_H
