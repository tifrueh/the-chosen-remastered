// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <vector>
#include "item.hpp"
#include "world.hpp"
#include "gameentity.hpp"

namespace chosen {
    class Player : public GameEntityWithInventory {
        private:
            chosen::Room *location;
        
        public:
            Player();
            void setName(const std::string &name);
            void setLocation(chosen::Room &room);
            Room *getLocation();
            std::string getLocationName();
            std::string getLocationDescription();
            std::vector<std::string> getFullLocationDescription();

            void move(const int &direction);
            void take(chosen::Item &item);
            void drop(chosen::Item &item);
            std::vector<std::string> getInventory();
    };
}
