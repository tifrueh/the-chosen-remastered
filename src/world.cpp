// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include <array>
#include <stdexcept>
#include "world.hpp"

chosen::Room::Room(const std::string &id, const std::string &name) : GameEntity(id, name, "GameEntity:Room") {
    this->description = "[THIS ROOM HAS NO DESCRIPTION]";
    hasDirection = {false, false, false, false};
}

void chosen::Room::setDescription(const std::string &description) {
    this->description = description;
}

std::string chosen::Room::getDescription() {
    return description;
}

std::array<std::string, 3> chosen::Room::getFullDescription() {
    std::array<std::string, 3> out;
    out[0] = name;
    out[1] = std::string(name.size(), '-');
    out[2] = description;

    return out;
}

void chosen::Room::addDoor(Door &door, const int &direction) {
    doors[direction] = &door;
    hasDirection[direction] = true;
    door.addRoom(this);
}

chosen::Door* chosen::Room::getDoor(const int &direction) {
    return doors[direction];
}

bool chosen::Room::hasDoorToDirection(const int &direction) {
    return hasDirection[direction];
}


chosen::Door::Door(const std::string &id) : GameEntity(id, "Door", "GameEntity:Door") {
    roomsConnected = 0;
}

void chosen::Door::addRoom(Room *room) {
    if (roomsConnected == 0) {
        rooms[0] = room;
        roomsConnected++;
    }
    else if (roomsConnected == 1) {
        rooms[1] = room;
        roomsConnected++;
    }
    else {
        throw std::out_of_range("A door cannot have more than two rooms");
    }
}

chosen::Room *chosen::Door::getOtherRoom(Room *room) {
    if (rooms[0] == room) {
        return rooms[1];
    }
    else if (rooms[1] == room) {
        return rooms[0];
    }
    else {
        return nullptr;
    }
}
