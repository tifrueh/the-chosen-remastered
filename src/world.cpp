// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include <array>
#include <vector>
#include <stdexcept>
#include "item.hpp"
#include "world.hpp"

chosen::Room::Room(const std::string &id, const std::string &name) : GameEntityWithInventory(id, "", name, "GameEntity:GameEntityWithInventory:Room") {
    this->description = "[THIS ROOM HAS NO DESCRIPTION]";
    hasDirection = {false, false, false, false, false, false};
    hasVisibleDirection = {false, false, false, false, false, false};
    visited = false;
}

std::string chosen::Room::getDoorString() {
    std::vector<std::string> directions;

    if (hasVisibleDirection[NORTH]) {
        directions.push_back("north");
    } 
    if (hasVisibleDirection[EAST]) {
        directions.push_back("east");
    }
    if (hasVisibleDirection[SOUTH]) {
        directions.push_back("south");
    }
    if (hasVisibleDirection[WEST]) {
        directions.push_back("west");
    }

    if (directions.size() == 1) {
        return "There is a door to the " + directions[0] + ".";
    }
    else if (directions.size() == 2) {
        return "There are doors to the " + directions[0] + " and to the " + directions[1] + ".";
    }
    else if (directions.size() == 3) {
        return "There are doors to the " + directions[0] + ", to the " + directions[1] + " and to the " + directions[2] + ".";
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

    if (hasVisibleDirection[UP]) {
        directions.push_back("up");
    }
    if (hasVisibleDirection[DOWN]) {
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

    for (chosen::Item *item : items) {
        out.back() += " " + item->getDescription();
    }

    out.push_back(getDoorString());
    out.push_back(getLadderString());

    return out;
}

std::vector<std::string> chosen::Room::getShortDescription() {
    std::vector<std::string> out;
    out.push_back(name);

    for (chosen::Item *item : items) {
        out.push_back(item->getDescription());
    }

    out.push_back(getDoorString());
    out.push_back(getLadderString());

    return out;
}

void chosen::Room::addLink(Link &link, const int &direction) {

    if (hasDirection[direction]) {
        throw std::logic_error("This room already has a link to this direction");
    }

    links[direction] = &link;
    hasDirection[direction] = true;

    if (link.isVisible()) {
        hasVisibleDirection[direction] = true;
    }

    link.addRoom(this);
}

chosen::Link* chosen::Room::getLink(const int &direction) {
    if (hasDirection[direction]) {
        return links[direction];
    }
    else {
        return nullptr;
    }
}

bool chosen::Room::hasLinkToDirection(const int &direction) {
    return hasDirection[direction];
}

bool chosen::Room::hasVisibleLinkToDirection(const int &direction) {
    return hasVisibleDirection[direction];
}

chosen::Link::Link(const std::string &id, const bool &visible) : GameEntity(id, "", "Link", "GameEntity:Link") {
    roomsConnected = 0;
    this->visible = visible;
    message = "";
}

bool chosen::Room::wasVisited() {
    return visited;
}

void chosen::Room::registerVisit() {
    visited = true;
}

bool chosen::Link::isVisible() {
    return visible;
}

std::string chosen::Link::getMessage() {
    return message;
}

void chosen::Link::setMessage(const std::string &message) {
    this->message = message;
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
