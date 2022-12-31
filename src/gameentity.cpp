// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include "gameentity.hpp"

chosen::GameEntity::GameEntity(const std::string &id, const std::string &name, const std::string &classId) {
    this->classId = classId;
    this->id = id;
    this->name = name;
}

chosen::GameEntity::GameEntity(const std::string &id, const std::string &name) {
    GameEntity(id, name, "GameEntity");
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
