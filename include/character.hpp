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
            std::string description;
            std::vector<std::string> conversation;
            std::string hugMessage;
        
            Character(const std::string &id, const std::string &article, const std::string &name, const std::string &classId);
        
        public:
            Character(const std::string &id, const std::string &article, const std::string &name);
            void setDescription(const std::string &description);
            std::string getDescription();
            void setConversation(const std::vector<std::string> &conversation);
            std::string getConversation();
            void setHugMessage(const std::string &message);
            std::string getHugMessage();
    };
}
