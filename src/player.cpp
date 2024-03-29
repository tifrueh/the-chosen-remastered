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
    alive = true;
    victory = false;
}

void chosen::Player::setName(const std::string &name) {
    this->name = name;
}

void chosen::Player::setLocation(chosen::Room &room) {
    location = &room;
}

void chosen::Player::setDefeatMessage(chosen::Character &character, chosen::Item &item, const std::string &message) {
    deathMessages[&character][&item] = message;
}

void chosen::Player::setVictoryMessage(chosen::Character &character, chosen::Item &item, const std::string &message) {
    victoryMessages[&character][&item] = message;
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

std::string chosen::Player::getDefeatMessage(chosen::Character &character, chosen::Item &item) {
    try {
        return deathMessages.at(&character).at(&item);
    }
    catch (std::out_of_range const&) {
        return character.getDefaultVictoryMessage();
    }
}

std::string chosen::Player::getVictoryMessage(chosen::Character &character, chosen::Item &item) {
    try {
        return victoryMessages.at(&character).at(&item);
    }
    catch (std::out_of_range const&) {
        return character.getDefaultDeathMessage();
    }
}

void chosen::Player::die() {
    alive = false;
}

void chosen::Player::win() {
    victory = true;
}

bool chosen::Player::isAlive() {
    return alive;
}

bool chosen::Player::hasWon() {
    return victory;
}

void chosen::Player::move(const int &direction) {
    if (!location->hasLinkToDirection(direction)) {
        throw std::logic_error("Movement through nonexisting link");
    }
    else if (location->getLink(direction)->getOtherRoom(*location) == nullptr) {
        throw std::logic_error("Movement through link with only one room");
    }

    Room *newLocation = location->getLink(direction)->getOtherRoom(*location);
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

bool chosen::Player::fight(chosen::Character &character, chosen::Item &item) {
    bool victory = character.evaluateFight(item);

    if (victory) {
        location->removeCharacter(character);
    }

    return victory;
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
