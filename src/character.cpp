// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in main.cpp


#include "character.hpp"

chosen::Character::Character(const std::string &id, 
                             const std::string &article, 
                             const std::string &name, 
                             const std::string &classId) : GameEntityWithInventory(id, article, name, classId) {
                                conversationCounter = 0;
                                description = cArticleName + " is here.";
}

chosen::Character::Character(const std::string &id,
                             const std::string &article,
                             const std::string &name) : GameEntityWithInventory(id, article, name, "GameEntity:GameEntityWithInventory:Character") {
                                conversationCounter = 0;
                                description = cArticleName + " is here.";
                             }

void chosen::Character::setDescription(const std::string &description) {
    this->description = description;
}

std::string chosen::Character::getDescription() {
    return description;
}

void chosen::Character::setConversation(const std::vector<std::string> &conversation) {
    this->conversation = conversation;
}

std::string chosen::Character::getConversation() {
    std::string out;

    if (conversationCounter < conversation.size()) {
        out = conversation.at(conversationCounter);
        conversationCounter++;
    }
    else {
        out = conversation.back();
    }

    return out;
}
