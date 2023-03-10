// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <array>
#include <vector>
#include "item.hpp"
#include "character.hpp"

#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define UP 4
#define DOWN 5

namespace chosen {

    class Room;
    class Link;

    class Room : public GameEntityWithInventory {
        private:
            bool visited;
            std::string description;
            std::array<Link*, 6> links;
            std::array<bool, 6> hasDirection;
            std::array<bool, 6> hasVisibleDirection;
            std::vector<Character*> characters;

            std::string getDoorString();
            std::string getLadderString();
        
        public:
            Room(const std::string &id, const std::string &name);
            void setDescription(const std::string &description);
            std::string getDescription();
            std::vector<std::string> getFullDescription();
            std::vector<std::string> getShortDescription();
            void addLink(Link &link, const int &direction);
            Link *getLink(const int &direction);
            bool hasLinkToDirection(const int &direction);
            bool hasVisibleLinkToDirection(const int &direction);
            void addCharacter(Character &character);
            bool hasCharacter(Character &character);
            bool hasAnyCharacter();
            void removeCharacter(Character &character);
            Character* getCharacterByAlias(const std::string &alias);
            bool wasVisited();
            void registerVisit();
    };

    class Link : public GameEntity {
        private:
            int roomsConnected;
            bool visible;
            std::string message;
            std::array<Room*, 2> rooms;
        
        public:
            Link(const std::string &id, const bool &visible);
            bool isVisible();
            std::string getMessage();
            void setMessage(const std::string &message);
            void addRoom(Room &room);
            Room *getOtherRoom(Room &room);
    };
}
