// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <stdexcept>
#include "item.hpp"
#include "world.hpp"
#include "player.hpp"

chosen::Player::Player() : GameEntityWithInventory("player", "", "Adventurer", "GameEntity:Player") {
    location = nullptr;
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

std::vector<std::string> chosen::Player::getFullLocationDescription() {
    return location->getFullDescription();
}

void chosen::Player::move(const int &direction) {
    if (!location->hasLinkToDirection(direction)) {
        throw std::logic_error("Movement through nonexisting link");
    }
    else if (location->getLink(direction)->getOtherRoom(location) == nullptr) {
        throw std::logic_error("Movement through link with only one room");
    }

    Room *newLocation = location->getLink(direction)->getOtherRoom(location);
    setLocation(*newLocation);
}

void chosen::Player::take(chosen::Item &item) {
    location->removeItem(item);
    this->addItem(item);
}

void chosen::Player::drop(chosen::Item &item) {
    this->removeItem(item);
    location->addItem(item);
}
