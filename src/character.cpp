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
    deadly = true;
    description = cArticleName + " is here.";
    hugMessage = cTheName + " recoils as you move closer. You decide not to press the matter.";
    defaultDeathMessage = "You kill " + theName + ".";
    defaultVictoryMessage = cTheName + " lands a fatal blow.";
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
    return isKillable;
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

void chosen::Character::enableScore() {
    scoring = true;
}

void chosen::Character::disableScore() {
    scoring = false;
}

bool chosen::Character::givesScore() {
    return scoring;
}

void chosen::Character::makeDeadly() {
    deadly = true;
}

void chosen::Character::makePeaceful() {
    deadly = false;
}

bool chosen::Character::isDeadly() {
    return deadly;
}

chosen::NPC::NPC(const std::string &id, 
                 const std::string &article, 
                 const std::string &name) : chosen::Character(id, article, name) {
    classId = "GameEntity:GameEntityWithInventory:Character:NPC";
    defaultDeathMessage = "You kill " + theName + ".\nThis wasn't right ... You feel sorry for " + theName + ".";
    defaultVictoryMessage = cTheName + " looks at you and seems quite bewildered.";
    deadly = false;
    scoring = false;
}

void chosen::NPC::addImmunity(chosen::Item &item) {
    immunities.push_back(&item);
}

bool chosen::NPC::isImmuneAgainst(chosen::Item &item) {
    bool immune = false;

    for (chosen::Item *nItem : immunities) {
        if (nItem == &item) {
            immune = true;
        }
    }

    return immune;
}

bool chosen::NPC::evaluateFight(chosen::Item &item) {
    if (!isKillable) {
        return false;
    }

    return !isImmuneAgainst(item);
}

chosen::Enemy::Enemy(const std::string &id, 
                     const std::string &article, 
                     const std::string &name) : chosen::Character(id, article, name) {
    classId = "GameEntity:GameEntityWithInventory:Character:Enemy";
    deadly = true;
    scoring = true;
}

void chosen::Enemy::addVulnerability(chosen::Item &item) {
    vulnerabilities.push_back(&item);
}

bool chosen::Enemy::isVulnerableAgainst(chosen::Item &item) {
    bool vulnerable = false;

    for (chosen::Item *nItem : vulnerabilities) {
        if (nItem == &item) {
            vulnerable = true;
        }
    }

    return vulnerable;
}

bool chosen::Enemy::evaluateFight(chosen::Item &weapon) {
    if (!isKillable) {
        return false;
    }

    return isVulnerableAgainst(weapon);
}

chosen::FighterNPC::FighterNPC(const std::string &id, 
                 const std::string &article, 
                 const std::string &name) : chosen::Enemy(id, article, name) {
    classId = "GameEntity:GameEntityWithInventory:Character:Enemy:FighterNPC";
    defaultVictoryMessage = cTheName + " did not wish you harm. But you already started the fight. You lose ...";
    deadly = true;
    scoring = false;
}
