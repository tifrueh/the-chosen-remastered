// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "item.hpp"

chosen::Item::Item(const std::string &id, const std::string &article, const std::string &name) : GameEntity(id, article, name) {
    classId = "GameEntity:Item";
    description = cArticleName + " is here.";
    initialDescription = description;
    isInInitialPosition = true;
    examinationDescription = "There is nothing special about " + theName + ".";
    scoreRequirement = 0;
}

void chosen::Item::setDescription(const std::string &description) {
    this->description = description;
}

void chosen::Item::setInitialDescription(const std::string &description) {
    this->initialDescription = description;
}

void chosen::Item::setExaminationDescription(const std::string &description) {
    this->examinationDescription = description;
}

std::string chosen::Item::getExaminationDescription() {
    return(examinationDescription);
}

std::string chosen::Item::getDescription() {
    if (isInInitialPosition) {
        return initialDescription;
    }
    else {
        return description;
    }
}

void chosen::Item::registerPickup() {
    isInInitialPosition = false;
}

void chosen::Item::setScoreRequirement(const int &score) {
    scoreRequirement = score;
}

bool chosen::Item::wieldable(const int &score) {
    return score >= scoreRequirement;
}

void chosen::Item::setReqUnmetMessage(const std::string &message) {
    reqUnmetMessage = message;
}

std::string chosen::Item::getReqUnmetMessage() {
    return reqUnmetMessage;
}

chosen::Item* chosen::GameEntityWithInventory::getItemByAlias(const std::string &alias) {
    for (chosen::Item* item : items) {
        if (item->hasAlias(alias)) {
            return item;
        }
    }
    return nullptr;
}

chosen::GameEntityWithInventory::GameEntityWithInventory(const std::string &id, 
                                                         const std::string &article, 
                                                         const std::string &name) : GameEntity(id, article, name) {
    classId = "GameEntity:GameEntityWithInventory";
}

bool chosen::GameEntityWithInventory::hasItem(chosen::Item &item) {
    std::vector<chosen::Item*>::iterator itemIterator;
    itemIterator = std::find(items.begin(), items.end(), &item);

    return itemIterator != items.end();
}

bool chosen::GameEntityWithInventory::hasAnyItem() {
    return items.size() != 0;
}

void chosen::GameEntityWithInventory::addItem(chosen::Item &item) {
    items.push_back(&item);
}

void chosen::GameEntityWithInventory::removeItem(chosen::Item &item) {
    std::vector<chosen::Item*>::iterator itemIterator;
    itemIterator = std::find(items.begin(), items.end(), &item);

    if (itemIterator == items.end()) {
        throw std::logic_error("Room doesn't have item that was tried to remove");
    }

    items.erase(itemIterator);
}
