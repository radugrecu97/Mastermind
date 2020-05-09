//
// Created by radugrecu97 on 5/9/20.
//


#include <Peg.h>

#include <utility>

Peg::Peg(std::string color) {
    this->color = std::move(color);
}

void Peg::setColor(std::string color) {
    this->color = color;
}

std::string Peg::getColor() {
    return this->color;
}
