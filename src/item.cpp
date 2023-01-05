// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "item.hpp"

chosen::Item::Item(const std::string &id, const std::string &article, const std::string &name) : GameEntity(id, article, name, "GameEntity:Item") {
    description = "";
}

void chosen::Item::setDescription(const std::string &description) {
    this->description = description;
}

std::string chosen::Item::getDescriptionLine() {
    return cArticleName + " is here, " + description;
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
                                                         const std::string &name,
                                                         const std::string &classId) : GameEntity(id, article, name, classId) {}

chosen::GameEntityWithInventory::GameEntityWithInventory(const std::string &id, 
                                                         const std::string &article, 
                                                         const std::string &name) : GameEntity(id, article, name, "GameEntity:GameEntityWithInventory") {}

bool chosen::GameEntityWithInventory::hasItem(chosen::Item &item) {
    std::vector<chosen::Item*>::iterator itemIterator;
    itemIterator = std::find(items.begin(), items.end(), &item);

    if (itemIterator == items.end()) {
        return false;
    }
    else {
        return true;
    }
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
