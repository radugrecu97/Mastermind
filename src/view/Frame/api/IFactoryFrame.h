//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_IFACTORYFRAME_H
#define MASTERMIND_IFACTORYFRAME_H

#include "IFrame.h"

class IFactoryFrame {
public:
    virtual IFrame* createFrame(uint8_t menuId) = 0;
};

#endif //MASTERMIND_IFACTORYFRAME_H
