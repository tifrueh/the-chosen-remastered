// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <vector>
#include "gameentity.hpp"

namespace chosen {
    class Item : public GameEntity {
        protected:
            std::string description;

        public:
            Item(const std::string &id, const std::string &article, const std::string &name);
            void setDescription(const std::string &description);
            std::string getDescriptionLine();
    };

    class GameEntityWithInventory : public GameEntity {
        protected:
            std::vector<Item*> items;

            GameEntityWithInventory(const std::string &id, const std::string &article, const std::string &name, const std::string &classId);
        
        public:
            GameEntityWithInventory(const std::string &id, const std::string &article, const std::string &name);
            bool hasItem(chosen::Item &item);
            bool hasAnyItem();
            void addItem(chosen::Item &item);
            void removeItem(chosen::Item &item);
            Item* getItemByAlias(const std::string &alias);
    };
}
