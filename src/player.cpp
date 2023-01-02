// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <stdexcept>
#include "world.hpp"
#include "player.hpp"

chosen::Player::Player() : GameEntity("player", "Adventurer", "GameEntity:Player") {
    location = NULL;
}

void chosen::Player::setName(const std::string &name) {
    this->name = name;
}

void chosen::Player::setLocation(chosen::Room &room) {
    location = &room;
}

chosen::Room *chosen::Player::getLocation() {
    return location;
}

std::string chosen::Player::getLocationName() {
    return location->getName();
}

std::string chosen::Player::getLocationDescription() {
    return location->getDescription();
}

std::array<std::string, 4> chosen::Player::getFullLocationDescription() {
    return location->getFullDescription();
}

void chosen::Player::move(const int &direction) {
    if (location->hasLinkToDirection(direction)) { 
        Room *newLocation = location->getLink(direction)->getOtherRoom(location);
        setLocation(*newLocation);
    }
    else {
        throw std::logic_error("Movement through nonexisting link");
    }
}
