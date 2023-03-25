// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include <array>
#include <map>
#include "tui.hpp"
#include "world.hpp"
#include "player.hpp"
#include "customstring.hpp"
#include "parser.hpp"
#include "resources.hpp"
#include "character.hpp"
#include "game.hpp"

chosen::Game::Game() {
    score = 0;
    moves = 0;
    running = true;

    initWorld();
}

void chosen::Game::gameloop() {
    
    initLoop();

    std::string command;


    while (running) {
        command = tui.tuiInput();
        cstr::trim(command);
        std::string errorMessage = "I do not know what you meant by " + command + ".";

        tui.tuiPrint("\n> " + command);

        cstr::lowercase(command);

        if (cprs::isCommand(command, "talk to")) {
            std::string talk = cprs::parseCommand(command, "talk to");
            cmdTalk(talk);
        }
        else if (cprs::isCommand(command, "talk")) {
            std::string talk = cprs::parseCommand(command, "talk");
            cmdTalk(talk);
        }
        else if (cprs::isCommand(command, "fight")) {
            std::array<std::string, 2> fight = cprs::parseCommand(command, "fight", "with");
            cmdFight(fight[0], fight[1]);
        }
        else if (cprs::isCommand(command, "take")) {
            std::string take = cprs::parseCommand(command, "take");
            cmdTake(take);
        }
        else if (cprs::isCommand(command, "drop")) {
            std::string drop = cprs::parseCommand(command, "drop");
            cmdDrop(drop);
        }
        else if (cprs::isCommand(command, "examine")) {
            std::string examine = cprs::parseCommand(command, "examine");
            cmdExamine(examine);
        }
        else if (cprs::isCommand(command, "say")) {
            tui.tuiPrint("Talking to yourself is said to be a sign of impending mental collapse.");
        }
        else if (cprs::isCommand(command, "hug")) {
            std::string hug = cprs::parseCommand(command, "hug");
            cmdHug(hug);
        }
        else if (cprs::isCommand(command, "lock")) {
            cmdLock();
        }
        else if (cprs::isCommand(command, "unlock")) {
            cmdUnlock();
        }
        else if (cprs::isCommand(command, "go")) {
            std::string go = cprs::parseCommand(command, "go");
            cmdGo(go);
        }
        else if (cprs::isCommand(command, "climb")) {
            std::string climb = cprs::parseCommand(command, "climb");
            cmdClimb(climb);
        }
        else if (command == "north" || command == "n") {
            movePlayer(NORTH);
        }
        else if (command == "east" || command == "e") {
            movePlayer(EAST);
        }
        else if (command == "south" || command == "s") {
            movePlayer(SOUTH);
        }
        else if (command == "west" || command == "w") {
            movePlayer(WEST);
        }
        else if (command == "up" || command == "u") {
            movePlayer(UP);
        }
        else if (command == "down" || command == "d") {
            movePlayer(DOWN);
        }
        else if (command == "scream") {
            cmdScream();
        }
        else if (command == "help") {
            cmdHelp();
        }
        else if (command == "inventory" || command == "i") {
            cmdInventory();
        }
        else if (command == "look" || command == "look around" || command == "l") {
            cmdLook();
        }
        else if (command == "clear") {
            cmdClear();
        }
        else if (command == "exit" || command == "quit") {
            cmdExit();
        }
        else if (command == "") {
            tui.tuiPrint("I beg your pardon?");
        }
        else {
            tui.tuiPrint(errorMessage);
        }

        if (throneRoom.getCharacterByAlias("an-harat") == nullptr) {
            player.win();
        }

        if (!player.isAlive() || player.hasWon()) {
            endGame();
        }

        moves++;
        tui.updateMoves(moves);
        tui.updateScore(score);
        tui.setLocation(player.getLocationName());
    }

    endLoop();
}

void chosen::Game::initWorld() {

    cellar.setDescription(crsrc::cellarDesc);
    cellar.addLink(cellarLadder, UP);
    
    cellarLadderRoom.setDescription(crsrc::cellarLadderDesc);
    cellarLadderRoom.addLink(cellarLadder, DOWN);
    cellarLadderRoom.addLink(ladderHallDoor, NORTH);

    hall.setDescription(crsrc::hallDesc);
    hall.addLink(ladderHallDoor, SOUTH);
    hall.addLink(hallWestHallDoor, WEST);
    hall.addLink(libraryEntranceHallDoor, NORTH);
    hall.addLink(hallEastHallDoor, EAST);

    westHallRoom.setDescription(crsrc::westHallRoomDesc);
    westHallRoom.addLink(hallWestHallDoor, EAST);
    westHallRoom.addLink(westHallTrophyDoor, WEST);

    trophyRoom.setDescription(crsrc::trophyRoomDesc);
    trophyRoom.addLink(westHallTrophyDoor, EAST);
    trophyRoom.addLink(trophyNSPassagewayDoor, NORTH);

    nsPassageway.setDescription(crsrc::nsPassagewayDesc);
    nsPassageway.addLink(trophyNSPassagewayDoor, SOUTH);
    nsPassageway.addLink(nsPassagewayStaffDoor, NORTH);

    staffRoom.setDescription(crsrc::staffRoomDesc);
    staffRoom.addLink(nsPassagewayStaffDoor, SOUTH);
    staffRoom.addLink(staffLibraryDoor, EAST);

    library.setDescription(crsrc::libraryDesc);
    library.addLink(staffLibraryDoor, WEST);
    library.addLink(libraryLibraryEntranceDoor, SOUTH);

    libraryEntrance.setDescription(crsrc::libraryEntranceDesc);
    libraryEntrance.addLink(libraryLibraryEntranceDoor, NORTH);
    libraryEntrance.addLink(libraryEntranceHallDoor, SOUTH);

    eastHallRoom.setDescription(crsrc::eastHallRoomDesc);
    eastHallRoom.addLink(hallEastHallDoor, WEST);
    eastHallRoom.addLink(eastHallThroneEntranceDoor, EAST);

    throneEntrance.setDescription(crsrc::throneEntranceDesc);
    throneEntrance.addLink(eastHallThroneEntranceDoor, WEST);
    throneEntrance.addLink(hiddenRoomLink, SOUTH);
    throneEntrance.addLink(throneDoor, NORTH);

    hiddenRoom.setDescription(crsrc::hiddenRoomDesc);
    hiddenRoom.addLink(hiddenRoomLink, NORTH);

    throneRoom.setDescription(crsrc::throneRoomDesc);
    throneRoom.addLink(throneDoor, SOUTH);

    hiddenRoomLink.setMessage("As you lay your hand upon the wall, you pass through it and emerge on the other side.");
    
    longsword.setDescription(crsrc::longswordDesc);
    longsword.setInitialDescription(crsrc::longswordInitDesc);
    longsword.setExaminationDescription(crsrc::longswordExDesc);
    longsword.addAlias("simple sword");
    cellar.addItem(longsword);

    crossbow.setDescription(crsrc::crossbowDesc);
    crossbow.setInitialDescription(crsrc::crossbowInitDesc);
    crossbow.setExaminationDescription(crsrc::crossbowExDesc);
    crossbow.addAlias("double-winged crossbow");
    crossbow.addAlias("small crossbow");
    trophyRoom.addItem(crossbow);

    swordsODD.setDescription(crsrc::swordsOddDescription);
    swordsODD.setInitialDescription(crsrc::swordsOddInitDescription);
    swordsODD.setExaminationDescription(crsrc::swordsOddExDescription);
    swordsODD.addAlias("swords");
    swordsODD.setScoreRequirement(5);
    swordsODD.setReqUnmetMessage(crsrc::swordsOddReqUnmetMessage);
    hiddenRoom.addItem(swordsODD);

    fireWand.setDescription(crsrc::fireWandDesc);
    fireWand.setInitialDescription(crsrc::fireWandInitDesc);
    fireWand.setExaminationDescription(crsrc::fireWandExDesc);
    fireWand.addAlias("wand");
    fireWand.addAlias("fire wand");
    fireWand.addAlias("wood");
    fireWand.addAlias("piece of wood");
    hall.addItem(fireWand);

    holyWater.setDescription(crsrc::holyWaterDesc);
    holyWater.setInitialDescription(crsrc::holyWaterInitDesc);
    holyWater.setExaminationDescription(crsrc::holyWaterExDesc);
    holyWater.addAlias("water");
    holyWater.addAlias("holy water");
    holyWater.addAlias("bottle");
    library.addItem(holyWater);

    stranger.setDescription(crsrc::strangerDesc);
    stranger.setConversation(crsrc::strangerConversation);
    stranger.setDefaultVictoryMessage(crsrc::strangerDefVictoryMsg);
    stranger.setDefaultDeathMessage(crsrc::strangerDefDeathMsg);
    stranger.addVulnerability(fireWand);
    stranger.addVulnerability(swordsODD);
    hall.addCharacter(stranger);
    player.setDefeatMessage(stranger, longsword, crsrc::defeatStrangerLongsword);

    warrioress.setDescription(crsrc::warrioressDesc);
    warrioress.setConversation(crsrc::warrioressConversation);
    warrioress.addVulnerability(fireWand);
    warrioress.addVulnerability(swordsODD);
    nsPassageway.addCharacter(warrioress);

    elliot.setDescription(crsrc::elliotDesc);
    elliot.setHugMessage(crsrc::elliotHug);
    elliot.setDefaultDeathMessage(crsrc::elliotDefDeathMsg);
    player.setDefeatMessage(elliot, holyWater, crsrc::defeatElliotWater);
    elliot.addImmunity(holyWater);
    westHallRoom.addCharacter(elliot);

    hag.setDescription(crsrc::hagDesc);
    hag.setConversation(crsrc::hagConversation);
    hag.addAlias("hag");
    hag.addAlias("woman");
    hag.addAlias("old woman");
    staffRoom.addCharacter(hag);

    scholar.setDescription(crsrc::scholarDesc);
    scholar.setConversation(crsrc::scholarConversation);
    scholar.addAlias("learned man");
    library.addCharacter(scholar);

    demonKing.setDescription(crsrc::demonKingDesc);
    demonKing.setConversation(crsrc::demonKingConversation);
    demonKing.setHugMessage(crsrc::demonKingHugMessage);
    demonKing.setDefaultVictoryMessage(crsrc::demonKingDefVictoryMsg);
    demonKing.addAlias("demon king");
    demonKing.addAlias("king");
    demonKing.addVulnerability(swordsODD);
    throneRoom.addCharacter(demonKing);
    player.setVictoryMessage(demonKing, swordsODD, crsrc::victoryDemonKingSwords);
}

void chosen::Game::initLoop() {
    tui.setLocation("Copyright");

    tui.tuiPrint<6>(crsrc::welcomeMessage);
    tui.waitForInput();
    tui.clear();

    tui.setLocation("Unknown location");

    tui.tuiPrint<11>(crsrc::intro);

    std::string playerName;
    playerName = tui.tuiInput("\nWhat is your name?\n");
    cstr::trim(playerName);

    while (playerName == "") {
        playerName = tui.tuiInput("The memory of your name has become quite hazy ... But you try again.\nWhat is your name?\n");
    }

    crsrc::elliotConversation.at(0) = "Hey, " + playerName + "! Long time no see!";
    elliot.setConversation(crsrc::elliotConversation);

    player.setName(playerName);

    tui.tuiPrint("You look around.\n");

    player.setLocation(cellar);
    tui.setLocation(player.getLocationName());

    tui.tuiPrint(player.getFullLocationDescription());
    player.getLocation()->registerVisit();
}

void chosen::Game::endLoop() {

    tui.tuiPrintNewline();

    if (player.hasWon()) {
        tui.tuiPrint(crsrc::victoryMessage);
    }

    switch (score) {
        case 0:
            tui.tuiPrint("You vanquished not a single enemy during the game.");
            break;
        
        case 1:
            tui.tuiPrint("You vanquished 1 enemy during the game.");
            break;
        
        default:
            tui.tuiPrint("You vanquished " + std::to_string(score) + " enemies during the game.");
    }

    tui.waitForInput("\n[Hit any key to exit.]");
}

void chosen::Game::endGame() {
    running = false;
}

void chosen::Game::cmdTalk(std::string character) {
    
    if (!player.getLocation()->hasAnyCharacter()) {
        tui.tuiPrint("There is no one here to listen to your beautiful voice.");
        return;
    }
    
    if (character == "") {

        character = tui.tuiInput("To whom to want to talk?");

        if (character == "") {
            tui.tuiPrint("Never mind.");
            return;
        }
        else {
            tui.tuiPrintNewline();
            tui.tuiPrint("> " + character);
        }
    }


    chosen::Character* characterPtr = player.getLocation()->getCharacterByAlias(character);

    if (characterPtr == nullptr) {
        tui.tuiPrint("There is no one called " + character + " here.");
        return;
    }
    else {
        tui.tuiPrint(player.talk(*characterPtr));
    }
}

void chosen::Game::cmdFight(std::string character, std::string item) {
    bool victory = true;

    if (!player.getLocation()->hasAnyCharacter()) {
        tui.tuiPrint("There is no one here whom you could fight.");
        return;
    } 
    else if (!player.hasAnyItem()) {
        tui.tuiPrint("You do not have anything to fight with.");
        return;
    }
    
    if (character == "") {

        character = tui.tuiInput("Whom do you want to fight?");

        if (character == "") {
            tui.tuiPrint("Never mind.");
            return;
        }
        else {
            tui.tuiPrintNewline();
            tui.tuiPrint("> " + character);
        }
    }

    if (item == "") {

        item = tui.tuiInput("With what do you want to fight?");

        if (item == "") {
            tui.tuiPrint("Never mind.");
            return;
        }
        else {
            tui.tuiPrintNewline();
            tui.tuiPrint("> " + item);
        }
    }

    chosen::Character *characterPtr = player.getLocation()->getCharacterByAlias(character);
    chosen::Item *itemPtr = player.getItemByAlias(item);

    if (characterPtr == nullptr) {
        tui.tuiPrint("There is no one called " + character + " here.");
        return;
    }
    else if (itemPtr == nullptr) {
        tui.tuiPrint("You do not have any item called " + item + ".");
        return;
    }
    
    if (itemPtr->wieldable(score)){
        victory = player.fight(*characterPtr, *itemPtr);
    }
    else {
        tui.tuiPrint(itemPtr->getReqUnmetMessage());
        victory = false;
    }

    if (victory) {
        tui.tuiPrint(player.getVictoryMessage(*characterPtr, *itemPtr));

        if (characterPtr->givesScore()) {
            score += 1;
        }
    } 
    else {
        tui.tuiPrint(player.getDefeatMessage(*characterPtr, *itemPtr));
        
        if (characterPtr->isDeadly()) {
            player.die();
        }
    }
}

void chosen::Game::cmdTake(std::string item) {

    if (!player.getLocation()->hasAnyItem()) {
        tui.tuiPrint("There is nothing here to take.");
        return;
    }
    
    if (item == "") {
        
        item = tui.tuiInput("What do you want to take?");

        if (item == "") {
            tui.tuiPrint("Never mind.");
            return;
        }
        else {
            tui.tuiPrintNewline();
            tui.tuiPrint("> " + item);
        }
    }

    chosen::Item* itemPtr = player.getLocation()->getItemByAlias(item);

    if (itemPtr == nullptr) {
        tui.tuiPrint("There is no item called " + item + " here.");
        return;
    }
    else {
        player.take(*itemPtr);
        tui.tuiPrint("Taken.");
    }
}

void chosen::Game::cmdDrop(std::string item) {

    if (!player.hasAnyItem()) {
        tui.tuiPrint("You do not have anything to drop.");
        return;
    }
    
    if (item == "") {

        item = tui.tuiInput("What do you want to drop?");

        if (item == "") {
            tui.tuiPrint("Never mind.");
            return;
        }
        else {
            tui.tuiPrintNewline();
            tui.tuiPrint("> " + item);
        }
    }

    chosen::Item* itemPtr = player.getItemByAlias(item);

    if (itemPtr == nullptr) {
        tui.tuiPrint("You do not have any item called " + item + ".");
        return;
    }
    else {
        player.drop(*itemPtr);
        tui.tuiPrint("Dropped.");
    }
}

void chosen::Game::cmdExamine(std::string item) {

    if (!player.hasAnyItem()) {
        tui.tuiPrint("You do not have anything to examine.");
        return;
    }
    
    if (item == "") {

        item = tui.tuiInput("What do you want to examine?");

        if (item == "") {
            tui.tuiPrint("Never mind.");
            return;
        }
        else {
            tui.tuiPrintNewline();
            tui.tuiPrint("> " + item);
        }
    }

    chosen::Item* itemPtr = player.getItemByAlias(item);

    if (itemPtr == nullptr) {
        tui.tuiPrint("You do not have any item called " + item + ".");
        return;
    }
    else {
        tui.tuiPrint(player.examine(*itemPtr));
    }
}

void chosen::Game::cmdHug(std::string character) {
    if (!player.getLocation()->hasAnyCharacter()) {
        tui.tuiPrint("There is no one here to receive your warm embrace.");
        return;
    }
    
    if (character == "") {

        character = tui.tuiInput("Whom do you want to hug?");

        if (character == "") {
            tui.tuiPrint("Never mind.");
            return;
        }
        else {
            tui.tuiPrintNewline();
            tui.tuiPrint("> " + character);
        }
    }

    chosen::Character *chPtr = player.getLocation()->getCharacterByAlias(character);

    if (chPtr == nullptr) {
        tui.tuiPrint("There is no one called " + character + " here.");
    }
    else {
        tui.tuiPrint(player.hug(*chPtr));
    }
}

void chosen::Game::cmdOpen() {
    tui.tuiPrint("cmd: open a door");
}

void chosen::Game::cmdClose() {
    tui.tuiPrint("cmd: close a door");
}

void chosen::Game::cmdLock() {
    tui.tuiPrint("cmd: lock a door");
}

void chosen::Game::cmdUnlock() {
    tui.tuiPrint("cmd: unlock a door");
}

void chosen::Game::movePlayer(const int &direction) {
    
    if (!player.getLocation()->hasLinkToDirection(direction)) {

        if (direction == UP) {
            tui.tuiPrint("You jump. Nothing happens. Do you expect me to applaud?");
        } 
        else if (direction == DOWN) {
            tui.tuiPrint("You kneel down and examine the floor. There doesn't seem to be a way down.");
        }
        else {
            tui.tuiPrint("You run head first into a wall and realize: You can't go that way.");
        }

        return;
    }

    std::string message = player.getLocation()->getLink(direction)->getMessage();
    if (message != "") {
        tui.tuiPrint(message + "\n");
    }

    player.move(direction);

    if (player.getLocation()->wasVisited()) {
        tui.tuiPrint(player.getShortLocationDescription());
    }
    else {
        tui.tuiPrint(player.getFullLocationDescription());
        player.getLocation()->registerVisit();
    }
}

void chosen::Game::cmdGo(std::string direction) {
    if (direction == "") {
        direction = tui.tuiInput("Go where?\n");
    }

    if (direction == "") {
        tui.tuiPrint("Never mind.");
    }
    else if (direction == "north") {
        movePlayer(NORTH);
    }
    else if (direction == "east") {
        movePlayer(EAST);
    }
    else if (direction == "south") {
        movePlayer(SOUTH);
    }
    else if (direction == "west") {
        movePlayer(WEST);
    }
    else if (direction == "up") {
        movePlayer(UP);
    }
    else if (direction == "down") {
        movePlayer(DOWN);
    }
    else {
        tui.tuiPrint("You should supply a direction!");
    }
}

void chosen::Game::cmdClimb(std::string direction) {
    if (direction == "") {
        direction = tui.tuiInput("Climb where?\n");
    }

    if (direction == "") {
        tui.tuiPrint("Never mind.");
    }
    else if (direction == "up") {
        movePlayer(UP);
    }
    else if (direction == "down") {
        movePlayer(DOWN);
    }
    else {
        tui.tuiPrint("You should supply a direction!");
    }
}

void chosen::Game::cmdScream() {
    tui.tuiPrint("cmd: scream (stop it ... get some help)");
}

void chosen::Game::cmdHelp() {
    tui.tuiPrint("cmd: help");
}

void chosen::Game::cmdInventory() {
    tui.tuiPrint(player.getInventory());
}

void chosen::Game::cmdLook() {
    tui.tuiPrint(player.getFullLocationDescription());
}

void chosen::Game::cmdClear() {
    tui.clear();
}

void chosen::Game::cmdExit() {
    std::string affirm = tui.tuiInput("Do you really wish to leave the game? (y is affermative)");
    if (affirm == "y") {
        endGame();
    }
}
