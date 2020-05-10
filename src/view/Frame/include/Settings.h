//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_SETTINGS_H
#define MASTERMIND_SETTINGS_H

#include <IFrame.h>

namespace frame {

    class Settings : public IFrame {
    public:
        std::string getText() override;
    };
}

#endif //MASTERMIND_SETTINGS_H
