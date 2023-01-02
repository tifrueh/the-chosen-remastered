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
    hasDirection = {false, false, false, false, false, false};
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

std::string chosen::Room::getLadderString() {
    std::vector<std::string> directions;

    if (hasDirection[UP]) {
        directions.push_back("up");
    }
    if (hasDirection[DOWN]) {
        directions.push_back("down");
    }

    if (directions.size() == 1) {
        return "There is a ladder leading " + directions[0] + ".";
    }
    else if (directions.size() == 2) {
        return "There is a ladder leading both up and down.";
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

std::vector<std::string> chosen::Room::getFullDescription() {
    std::vector<std::string> out;
    out.push_back(name);
    out.push_back(std::string(name.size(), '-'));
    out.push_back(description);
    out.push_back(getDoorString());
    out.push_back(getLadderString());

    return out;
}

void chosen::Room::addLink(Link &link, const int &direction) {
    links[direction] = &link;
    hasDirection[direction] = true;
    link.addRoom(this);
}

chosen::Link* chosen::Room::getLink(const int &direction) {
    if (hasDirection[direction]) {
        return links[direction];
    }
    else {
        throw std::out_of_range("This room has no link to this direction");
    }
}

bool chosen::Room::hasLinkToDirection(const int &direction) {
    return hasDirection[direction];
}


chosen::Link::Link(const std::string &id) : GameEntity(id, "Link", "GameEntity:Link") {
    roomsConnected = 0;
}

void chosen::Link::addRoom(Room *room) {
    if (roomsConnected == 0) {
        rooms[0] = room;
        roomsConnected++;
    }
    else if (roomsConnected == 1) {
        rooms[1] = room;
        roomsConnected++;
    }
    else {
        throw std::out_of_range("A link cannot have more than two rooms");
    }
}

chosen::Room *chosen::Link::getOtherRoom(Room *room) {
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
