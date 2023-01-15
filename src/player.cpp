// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in main.cpp


#include <stdexcept>
#include "item.hpp"
#include "character.hpp"
#include "world.hpp"
#include "player.hpp"

chosen::Player::Player() : GameEntityWithInventory("player", "", "Adventurer") {
    classId = "GameEntity:GameEntityWithInventory:Player";
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

std::vector<std::string> chosen::Player::getShortLocationDescription() {
    return location->getShortDescription();
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
    item.registerPickup();
}

void chosen::Player::drop(chosen::Item &item) {
    this->removeItem(item);
    location->addItem(item);
}

std::string chosen::Player::examine(chosen::Item &item) {
    return item.getExaminationDescription();
}

std::string chosen::Player::talk(chosen::Character &character) {
    return character.getConversation();
}

std::string chosen::Player::hug(chosen::Character &character) {
    return character.getHugMessage();
}

std::vector<std::string> chosen::Player::getInventory() {
    std::vector<std::string> out;

    if (!hasAnyItem()) {
        out.push_back("You are empty-handed.");
        return out;
    }

    out.push_back("You are carrying:");

    for (chosen::Item* item : items) {
        out.push_back("- " + item->getCArticleName());
    }
    
    return out;
}
