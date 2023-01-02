// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <array>
#include <vector>
#include "gameentity.hpp"

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define UP 4
#define DOWN 5

namespace chosen {

    class Room;
    class Link;

    class Room : public GameEntity {
        private:
            std::string description;
            std::array<Link*, 6> links;
            std::array<bool, 6> hasDirection;

            std::string getDoorString();
            std::string getLadderString();
        
        public:
            Room(const std::string &id, const std::string &name);
            void setDescription(const std::string &description);
            std::string getDescription();
            std::vector<std::string> getFullDescription();
            void addLink(Link &link, const int &direction);
            Link *getLink(const int &direction);
            bool hasLinkToDirection(const int &direction);
    };

    class Link : public GameEntity {
        private:
            int roomsConnected;
            std::array<Room*, 2> rooms;
        
        public:
            Link(const std::string &id);
            void addRoom(Room *room);
            Room *getOtherRoom(Room *room);
    };
}
