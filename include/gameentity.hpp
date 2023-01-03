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
            std::string article;

            std::string articleName;
            std::string cArticleName;
            std::string theName;
            std::string cTheName;

            GameEntity(const std::string &id, const std::string &article, const std::string &name, const std::string &classId);
        
        public:
            GameEntity(const std::string &id, const std::string &article, const std::string &name);
            std::string getClassId();
            std::string getId();
            std::string getName();
            std::string getArticleName();
            std::string getCArticleName();
            std::string getTheName();
            std::string getCTheName();
    };
}
