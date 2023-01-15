// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <vector>
#include "gameentity.hpp"

namespace chosen {
    class Item : public GameEntity {
        protected:
            std::string description;
            bool isInInitialPosition;
            std::string initialDescription;
            std::string examinationDescription;

        public:
            Item(const std::string &id, const std::string &article, const std::string &name);
            void setDescription(const std::string &description);
            void setInitialDescription(const std::string &description);
            void setExaminationDescription(const std::string &description);
            std::string getExaminationDescription();
            std::string getDescription();
            void registerPickup();
    };

    class GameEntityWithInventory : public GameEntity {
        protected:
            std::vector<Item*> items;
        
        public:
            GameEntityWithInventory(const std::string &id, const std::string &article, const std::string &name);
            bool hasItem(Item &item);
            bool hasAnyItem();
            void addItem(Item &item);
            void removeItem(Item &item);
            Item* getItemByAlias(const std::string &alias);
    };
}
