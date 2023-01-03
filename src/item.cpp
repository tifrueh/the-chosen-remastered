// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
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
