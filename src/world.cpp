// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include <array>
#include "world.hpp"

chosen::Room::Room(const std::string &id, const std::string &name) : GameEntity(id, name, "GameEntity:Room") {
    this->description = "[THIS ROOM HAS NO DESCRIPTION]";
}

void chosen::Room::setDescription(const std::string &description) {
    this->description = description;
}

std::string chosen::Room::getDescription() {
    return description;
}

std::array<std::string, 3> chosen::Room::getFullDescription() {
    std::array<std::string, 3> out;
    out[0] = name;
    out[1] = std::string(name.size(), '-');
    out[2] = description;

    return out;
}
