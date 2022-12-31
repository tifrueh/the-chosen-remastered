// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>

namespace chosen {
    class GameEntity {
        protected: 
            std::string classId;
            std::string id;
            std::string name;
            GameEntity(const std::string &id, const std::string &name, const std::string &classId);
        
        public:
            GameEntity(const std::string &id, const std::string &name);
            std::string getClassId();
            std::string getId();
            std::string getName();
    };
}
