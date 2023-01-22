// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in main.cpp


#include "character.hpp"

chosen::Character::Character(const std::string &id,
                             const std::string &article,
                             const std::string &name) : GameEntityWithInventory(id, article, name) {
    classId = "GameEntity:GameEntityWithInventory:Character";
    conversationCounter = 0;
    isKillable = true;
    description = cArticleName + " is here.";
    hugMessage = cTheName + " recoils as you move closer. You decide not to press the matter.";
    defaultDeathMessage = "You kill " + theName + ".";
    defaultVictoryMessage = "You start a fight with " + theName + ". You lose ...\nYou die ...";
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

void chosen::Character::makeInvincible() {
    isKillable = false;
}

bool chosen::Character::evaluateFight(chosen::Item &weapon) {
    if (isKillable == false) {
        return false;
    }

    return !isImmuneAgaints(weapon);
}

void chosen::Character::setDefaultDeathMessage(const std::string &message) {
    defaultDeathMessage = message;
}

std::string chosen::Character::getDefaultDeathMessage() {
    return defaultDeathMessage;
}

void chosen::Character::setDefaultVictoryMessage(const std::string &message) {
    defaultVictoryMessage = message;
}

std::string chosen::Character::getDefaultVictoryMessage() {
    return defaultVictoryMessage;
}

void chosen::Character::addImmunity(chosen::Item &item) {
    immunities.push_back(&item);
}

bool chosen::Character::isImmuneAgaints(chosen::Item &item) {
    bool immune = false;

    for (chosen::Item *nItem : immunities) {
        if (nItem == &item) {
            immune = true;
        }
    }

    return immune;
}
