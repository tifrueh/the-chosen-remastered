// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in main.cpp


#include "character.hpp"

chosen::Character::Character(const std::string &id,
                             const std::string &article,
                             const std::string &name) : GameEntityWithInventory(id, article, name) {
    classId = "GameEntity:GameEntityWithInventory:Character";
    conversationCounter = 0;
    description = cArticleName + " is here.";
    hugMessage = cTheName + " recoils as you move closer. You decide not to press the matter.";
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
    std::string out = "[" + cTheName + "]:\n";

    if (conversation.size() == 0) {
        out = cTheName + " seemingly does not want to talk to you.";
    }
    else if (conversationCounter < conversation.size()) {
        out += conversation.at(conversationCounter);
        conversationCounter++;
    }
    else {
        out += conversation.back();
    }

    return out;
}

void chosen::Character::setHugMessage(const std::string &message) {
    this->hugMessage = message;
}

std::string chosen::Character::getHugMessage(){
    return hugMessage;
}
