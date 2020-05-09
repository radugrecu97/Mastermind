//
// Created by radugrecu97 on 5/9/20.
//

#include <Util.h>

int8_t Util::validateUpperLetters(std::string str) {
    for(char& c : str) {
        if ((c < 65) || (c > 90)) {
            return -1;
        }
    }
    return 1;
}

