//
// Created by radugrecu97 on 5/9/20.
//

#ifndef MASTERMIND_UTIL_H
#define MASTERMIND_UTIL_H

#include <IUtil.h>

class Util: public IUtil {
public:
    //setToString
    int8_t validateUpperLetters(std::string str) override;
    int8_t validateUpperLettersAndStar(std::string str) override;
    int countUniqueCharacters(std::string str) override;
    int8_t validateNumbers(std::string str) override;
};

#endif //MASTERMIND_UTIL_H
