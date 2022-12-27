// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>

namespace chosen {
    class GameEntity {
        private: 
            std::string id;
            std::string name;
        
        public:
            GameEntity(const std::string &id);
            GameEntity(const std::string &id, const std::string &name);
            std::string getId();
            std::string getName();
            void setName(const std::string &name);
    };
}
