//
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_FACTORYFRAME_H
#define MASTERMIND_FACTORYFRAME_H

#include <IFactoryFrame.h>

class FactoryFrame : public IFactoryFrame {
public:
    IFrame* createFrame(uint8_t menuId) override;
};

#endif //MASTERMIND_FACTORYFRAME_H
