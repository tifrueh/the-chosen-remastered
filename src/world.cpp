// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include <array>
#include <vector>
#include <stdexcept>
#include "world.hpp"

chosen::Room::Room(const std::string &id, const std::string &name) : GameEntity(id, name, "GameEntity:Room") {
    this->description = "[THIS ROOM HAS NO DESCRIPTION]";
    hasDirection = {false, false, false, false};
}

std::string chosen::Room::getDoorString() {
    std::vector<std::string> directions;

    if (hasDirection[NORTH] == true) {
        directions.push_back("north");
    } 
    if (hasDirection[EAST] == true) {
        directions.push_back("east");
    }
    if (hasDirection[SOUTH] == true) {
        directions.push_back("south");
    }
    if (hasDirection[WEST] == true) {
        directions.push_back("west");
    }

    if (directions.size() == 1) {
        return "There is a door to the " + directions[0] + ".";
    }
    else if (directions.size() == 2) {
        return "There are doors to the " + directions[0] + " and to the " + directions[1] + ".";
    }
    else if (directions.size() == 3) {
        return "There are doors to the " + directions[0] + " , to the " + directions[1] + " and to the " + directions[2] + ".";
    }
    else if (directions.size() == 4) {
        return "There are doors to all directions.";
    }
    else {
        return "";
    }
}

void chosen::Room::setDescription(const std::string &description) {
    this->description = description;
}

std::string chosen::Room::getDescription() {
    return description;
}

std::array<std::string, 4> chosen::Room::getFullDescription() {
    std::array<std::string, 4> out;
    out[0] = name;
    out[1] = std::string(name.size(), '-');
    out[2] = description;
    out[3] = getDoorString();

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
