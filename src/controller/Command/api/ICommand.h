//std::string getDisplayText() = 0;
// Created by radugrecu97 on 5/10/20.
//

#ifndef MASTERMIND_ICOMMAND_H
#define MASTERMIND_ICOMMAND_H

#include <cstdint>
#include <string>

class ICommand {
public:
    virtual int8_t execute(std::string data) = 0;
    virtual std::string getDisplayText() = 0;
};

#endif //MASTERMIND_ICOMMAND_H
