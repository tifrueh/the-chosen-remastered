// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <array>
#include "gameentity.hpp"

namespace chosen {
    class Room : public GameEntity {
        private:
            std::string description;
        
        public:
            Room(const std::string &id, const std::string &name);
            void setDescription(const std::string &description);
            std::string getDescription();
            std::array<std::string, 3> getFullDescription();
    };
}
