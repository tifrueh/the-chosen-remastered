// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


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

std::string chosen::Player::getLocationName() {
    return location->getName();
}

std::string chosen::Player::getLocationDescription() {
    return location->getDescription();
}

std::array<std::string, 3> chosen::Player::getFullLocationDescription() {
    return location->getFullDescription();
}

void chosen::Player::move(const int &direction) {
    Room *newLocation = location->getDoor(direction)->getOtherRoom(location);
    setLocation(*newLocation);
}
