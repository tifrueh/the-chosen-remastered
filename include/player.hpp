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
            chosen::Room *location;
            std::map<Character*, std::map<Item*, std::string>> deathMessages;
            std::map<Character*, std::map<Item*, std::string>> victoryMessages;
        
        public:
            Player();
            void setName(const std::string &name);
            void setLocation(chosen::Room &room);
            void setDeathMessage(chosen::Character &character, chosen::Item &item, const std::string &message);
            void setVictoryMessage(chosen::Character &character, chosen::Item &item, const std::string &message);
            Room *getLocation();
            std::string getLocationName();
            std::string getLocationDescription();
            std::vector<std::string> getFullLocationDescription();
            std::vector<std::string> getShortLocationDescription();
            std::string getDeathMessage(chosen::Character &character, chosen::Item &item);
            std::string getVictoryMessage(chosen::Character &character, chosen::Item &item);

            void move(const int &direction);
            void take(chosen::Item &item);
            void drop(chosen::Item &item);
            bool fight(chosen::Character &character, chosen::Item &item);
            std::string talk(chosen::Character &character);
            std::string hug(chosen::Character &character);
            std::string examine(chosen::Item &item);
            std::vector<std::string> getInventory();
    };
}
