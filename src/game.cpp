// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include "tui.hpp"
#include "world.hpp"
#include "player.hpp"
#include "customstring.hpp"
#include "parser.hpp"
#include "resources.hpp"
#include "character.hpp"
#include "game.hpp"

chosen::Game::Game() {
    state = 0;
    score = 0;
    moves = 0;

    initWorld();
}

void chosen::Game::gameloop() {
    
    initLoop();

    std::string command;


    while (state == 0) {
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
            cmdFight();
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
            cmdHug();
        }
        else if (cprs::isCommand(command, "open")) {
            cmdOpen();
        }
        else if (cprs::isCommand(command, "close")) {
            cmdClose();
        }
        else if (cprs::isCommand(command, "lock")) {
            cmdLock();
        }
        else if (cprs::isCommand(command, "unlock")) {
            cmdUnlock();
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

        moves++;
        tui.updateMoves(moves);
        tui.updateScore(score);
        tui.setLocation(player.getLocationName());
    }
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
    hiddenRoom.addItem(swordsODD);

    fireWand.setDescription(crsrc::fireWandDesc);
    fireWand.setInitialDescription(crsrc::fireWandInitDesc);
    fireWand.setExaminationDescription(crsrc::fireWandExDesc);
    fireWand.addAlias("wand");
    fireWand.addAlias("fire wand");
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
    hall.addCharacter(stranger);

    elliot.setDescription(crsrc::elliotDesc);
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
}

void chosen::Game::initLoop() {
    tui.setLocation("Unknown location");

    tui.tuiPrint<6>(crsrc::welcomeMessage);

    tui.tuiNapMs(4000);
    tui.tuiPrintNewline();

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

void chosen::Game::cmdTalk(std::string character) {
    
    if (!player.getLocation()->hasAnyCharacter()) {
        tui.tuiPrint("There is no one here to listen to your beautiful voice.");
        return;
    }
    else if (character == "") {
        character = tui.tuiInput("To whom to want to talk?");
    }

    chosen::Character* characterPtr = player.getLocation()->getCharacterByAlias(character);

    if (character == "") {
        tui.tuiPrint("Never mind.");
        return;
    }
    else if (characterPtr == nullptr) {
        tui.tuiPrint("There is no one called " + character + " here.");
        return;
    }
    else {
        tui.tuiPrint(player.talk(*characterPtr));
    }
}

void chosen::Game::cmdFight() {
    tui.tuiPrint("cmd: fight someone");
}

void chosen::Game::cmdTake(std::string item) {

    if (!player.getLocation()->hasAnyItem()) {
        tui.tuiPrint("There is nothing here to take.");
        return;
    }
    else if (item == "") {
        item = tui.tuiInput("What do you want to take?");
    }

    chosen::Item* itemPtr = player.getLocation()->getItemByAlias(item);

    if (item == "") {
        tui.tuiPrint("Never mind.");
        return;
    }
    else if (itemPtr == nullptr) {
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
    else if (item == "") {
        item = tui.tuiInput("What do you want to drop?");
    }

    chosen::Item* itemPtr = player.getItemByAlias(item);

    if (item == "") {
        tui.tuiPrint("Never mind.");
        return;
    }
    else if (itemPtr == nullptr) {
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
    else if (item == "") {
        item = tui.tuiInput("What do you want to examine?");
    }

    chosen::Item* itemPtr = player.getItemByAlias(item);

    if (item == "") {
        tui.tuiPrint("Never mind.");
        return;
    }
    else if (itemPtr == nullptr) {
        tui.tuiPrint("You do not have any item called " + item + ".");
        return;
    }
    else {
        tui.tuiPrint(player.examine(*itemPtr));
    }
}

void chosen::Game::cmdHug() {
    tui.tuiPrint("cmd: hug someone");
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
        state = 1;
        tui.waitForInput("\n[Hit any key to exit]");
    }
}
