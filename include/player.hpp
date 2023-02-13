// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <vector>
#include <map>
#include "item.hpp"
#include "world.hpp"
#include "character.hpp"
#include "gameentity.hpp"

namespace chosen {
    class Player : public GameEntityWithInventory {
        private:
            Room *location;
            std::map<Character*, std::map<Item*, std::string>> deathMessages;
            std::map<Character*, std::map<Item*, std::string>> victoryMessages;
        
        public:
            Player();
            void setName(const std::string &name);
            void setLocation(Room &room);
            void setDeathMessage(Character &character, Item &item, const std::string &message);
            void setVictoryMessage(Character &character, Item &item, const std::string &message);
            Room *getLocation();
            std::string getLocationName();
            std::string getLocationDescription();
            std::vector<std::string> getFullLocationDescription();
            std::vector<std::string> getShortLocationDescription();
            std::string getDeathMessage(Character &character, Item &item);
            std::string getVictoryMessage(Character &character, Item &item);

            void move(const int &direction);
            void take(Item &item);
            void drop(Item &item);
            bool fight(Character &character, Item &item);
            std::string talk(Character &character);
            std::string hug(Character &character);
            std::string examine(Item &item);
            std::vector<std::string> getInventory();
    };
}
