//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_IUTIL_H
#define MASTERMIND_IUTIL_H

#include <string>

class IUtil {
public:
    //setToString
    virtual int8_t validateUpperLetters(std::string str) = 0;
    virtual int8_t validateUpperLettersAndStar(std::string str) = 0;
    virtual int countUniqueCharacters(std::string str) = 0;
    virtual int8_t validateNumbers(std::string str) = 0;
};

#endif //MASTERMIND_IUTIL_H
