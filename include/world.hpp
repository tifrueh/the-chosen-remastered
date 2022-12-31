// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <array>
#include "gameentity.hpp"

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

namespace chosen {

    class Room;
    class Door;

    class Room : public GameEntity {
        private:
            std::string description;
            std::array<Door*, 4> doors;
            std::array<bool, 4> hasDirection;
        
        public:
            Room(const std::string &id, const std::string &name);
            void setDescription(const std::string &description);
            std::string getDescription();
            std::array<std::string, 3> getFullDescription();
            void addDoor(Door &door, const int &direction);
            Door *getDoor(const int &direction);
            bool hasDoorToDirection(const int &direction);
    };

    class Door : public GameEntity {
        private:
            int roomsConnected;
            std::array<Room*, 2> rooms;
        
        public:
            Door(const std::string &id);
            void addRoom(Room *room);
            Room *getOtherRoom(Room *room);
    };
}
