// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <vector>
#include "item.hpp"

namespace chosen {
    class Character : public GameEntityWithInventory {
        protected:
            long unsigned int conversationCounter;
            bool isKillable;
            std::string description;
            std::vector<std::string> conversation;
            std::string hugMessage;
            std::string defaultDeathMessage;
            std::string defaultVictoryMessage;
                
        public:
            Character(const std::string &id, const std::string &article, const std::string &name);
            void setDescription(const std::string &description);
            std::string getDescription();
            void setConversation(const std::vector<std::string> &conversation);
            std::string getConversation();
            void setHugMessage(const std::string &message);
            std::string getHugMessage();
            void makeInvincible();
            virtual bool evaluateFight(Item &weapon);
            void setDefaultDeathMessage(const std::string &message);
            std::string getDefaultDeathMessage();
            void setDefaultVictoryMessage(const std::string &message);
            std::string getDefaultVictoryMessage();
    };

    class NPC : public Character {
        protected:
            std::vector<Item*> immunities;
        
        public:
            NPC(const std::string &id, const std::string &article, const std::string &name);
            void addImmunity(Item &item);
            bool isImmuneAgainst(Item &item);
            bool evaluateFight(Item &weapon);
    };

    class Enemy : public Character {
        protected:
            std::vector<Item*> vulnerabilities;

        public:
            Enemy(const std::string &id, const std::string &article, const std::string &name);
            void addVulnerability(Item &item);
            bool isVulnerableAgainst(Item &item);
            bool evaluateFight(Item &weapon);
    };
}
