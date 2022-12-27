// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include "player.hpp"

class chosen::Player {
    private:
        std::string name;

    public:
        void setName(const std::string &setToName);
        std::string getName();
};

void chosen::Player::setName(const std::string &setToName) {
    name = setToName;
}

std::string chosen::Player::getName() {
    return name;
}
