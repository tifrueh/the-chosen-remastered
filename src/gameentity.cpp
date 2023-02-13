// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include <vector>
#include "customstring.hpp"
#include "gameentity.hpp"

chosen::GameEntity::GameEntity(const std::string &id, const std::string &article, const std::string &name) {
    this->classId = "GameEntity";
    this->id = id;
    this->name = name;
    this->article = article;
    if (article == "") {
        articleName = name;
        cArticleName = name;
        theName = name;
        cTheName = name;
    }
    else {
        articleName = article + " " + name;
        cArticleName = cstr::capitaliseToNew(articleName);
        theName = "the " + name;
        cTheName = "The " + name;
    }

    aliases.push_back(cstr::lowercaseToNew(name));
    aliases.push_back(cstr::lowercaseToNew(articleName));
    aliases.push_back(cstr::lowercaseToNew(theName));
}

std::string chosen::GameEntity::getClassId() {
    return classId;
}

std::string chosen::GameEntity::getId() {
    return id;
}

std::string chosen::GameEntity::getName() {
    return name;
}

std::string chosen::GameEntity::getArticleName() {
    return articleName;
}

std::string chosen::GameEntity::getCArticleName() {
    return cArticleName;
}

std::string chosen::GameEntity::getTheName() {
    return theName;
}

std::string chosen::GameEntity::getCTheName() {
    return cTheName;
}

void chosen::GameEntity::addAlias(const std::string &alias) {
    aliases.push_back(cstr::lowercaseToNew(alias));
    aliases.push_back("a " + cstr::lowercaseToNew(alias));
    aliases.push_back("the " + cstr::lowercaseToNew(alias));
}

bool chosen::GameEntity::hasAlias(const std::string &alias) {
    for (std::string aliasN : aliases) {
        if (aliasN == alias) {
            return true;
        }
    }
    return false;
}

std::vector<std::string> chosen::GameEntity::getAliases() {
    return aliases;
}
