//
// Created by radugrecu97 on 5/9/20.
//

#include <Util.h>
#include <error_codes.h>
#include <algorithm>

int8_t Util::validateUpperLetters(std::string str) {
    for(char c : str) {
        if ((c < 65) || (c > 90)) {
            return codes::INVALID_INPUT;
        }
    }
    return codes::SUCCESS;
}

int8_t Util::validateUpperLettersAndStar(std::string str) {
    for(char c : str) {
        if (((c < 'A') || (c > 'Z')) && (c != '*')) {
            return codes::INVALID_INPUT;
        }
    }
    return codes::SUCCESS;
}

int Util::countUniqueCharacters(std::string str)
{
    // e.g. str = "abcdefabc"
    std::sort(str.begin(), str.end());
    // e.g. str = "aabbccdef"
    auto i = std::unique(str.begin(), str.end());
    // e.g. str = "abcdef???" with i pointing to first "?"
    // (in other words, i = str.begin() + 6)
    // Note that "?" is an unknown character, not an actual question mark
    return i - str.begin();
    // returns 6
}