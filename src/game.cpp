// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include "tui.hpp"
#include "world.hpp"
#include "player.hpp"
#include "customstring.hpp"
#include "parser.hpp"
#include "resources.hpp"
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
            cmdTalkTo();
        }
        else if (cprs::isCommand(command, "talk")) {
            cmdTalk();
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
        else if (command == "north") {
            cmdNorth();
        }
        else if (command == "east") {
            cmdEast();
        }
        else if (command == "south") {
            cmdSouth();
        }
        else if (command == "west") {
            cmdWest();
        }
        else if (command == "up") {
            cmdUp();
        }
        else if (command == "down") {
            cmdDown();
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

    cellar.setDescription(crsrc::cellar_txt);
    cellar.addLink(cellarLadder, UP);
    
    cellarLadderRoom.setDescription(crsrc::cellar_ladder_txt);
    cellarLadderRoom.addLink(cellarLadder, DOWN);
    cellarLadderRoom.addLink(ladderHallDoor, NORTH);

    hall.setDescription(crsrc::hall_txt);
    hall.addLink(ladderHallDoor, SOUTH);
    hall.addLink(hallWestHallDoor, WEST);
    hall.addLink(libraryEntranceHallDoor, NORTH);
    hall.addLink(hallEastHallDoor, EAST);

    westHallRoom.setDescription(crsrc::west_hall_room_txt);
    westHallRoom.addLink(hallWestHallDoor, EAST);
    westHallRoom.addLink(westHallTrophyDoor, WEST);

    trophyRoom.setDescription(crsrc::trophy_room_txt);
    trophyRoom.addLink(westHallTrophyDoor, EAST);
    trophyRoom.addLink(trophyNSPassagewayDoor, NORTH);

    nsPassageway.setDescription(crsrc::ns_passageway_txt);
    nsPassageway.addLink(trophyNSPassagewayDoor, SOUTH);
    nsPassageway.addLink(nsPassagewayStaffDoor, NORTH);

    staffRoom.setDescription(crsrc::staff_room_txt);
    staffRoom.addLink(nsPassagewayStaffDoor, SOUTH);
    staffRoom.addLink(staffLibraryDoor, EAST);

    library.setDescription(crsrc::library_txt);
    library.addLink(staffLibraryDoor, WEST);
    library.addLink(libraryLibraryEntranceDoor, SOUTH);

    libraryEntrance.setDescription(crsrc::library_entrance_txt);
    libraryEntrance.addLink(libraryLibraryEntranceDoor, NORTH);
    libraryEntrance.addLink(libraryEntranceHallDoor, SOUTH);

    eastHallRoom.setDescription(crsrc::east_hall_room_txt);
    eastHallRoom.addLink(hallEastHallDoor, WEST);
    eastHallRoom.addLink(eastHallThroneEntranceDoor, EAST);

    throneEntrance.setDescription(crsrc::throne_entrance_txt);
    throneEntrance.addLink(eastHallThroneEntranceDoor, WEST);
    throneEntrance.addLink(hiddenRoomLink, SOUTH);
    throneEntrance.addLink(throneDoor, NORTH);

    hiddenRoom.setDescription(crsrc::hidden_room_txt);
    hiddenRoom.addLink(hiddenRoomLink, NORTH);

    throneRoom.setDescription(crsrc::throne_room_txt);
    throneRoom.addLink(throneDoor, SOUTH);

    hiddenRoomLink.setMessage("As you lay your hand upon the wall, you pass through it and emerge on the other side.");
    
    longsword.setDescription(crsrc::longword_txt);
    cellar.addItem(longsword);
}

void chosen::Game::initLoop() {
    tui.setLocation("Unknown location");

    tui.tuiPrint<11>(crsrc::welcome_message_txt);

    std::string playerName;
    playerName = tui.tuiInput("\nWhat is your name?\n");
    cstr::trim(playerName);

    while (playerName == "") {
        playerName = tui.tuiInput("The memory of your name has become quite hazy ... But you try again.\nWhat is your name?\n");
    }

    player.setName(playerName);

    tui.tuiPrint("You look around.\n");

    player.setLocation(cellar);
    tui.setLocation(player.getLocationName());

    tui.tuiPrint(player.getFullLocationDescription());
}

void chosen::Game::cmdTalkTo() {
    tui.tuiPrint("cmd: talk to someone");
}

void chosen::Game::cmdTalk() {
    tui.tuiPrint("cmd: talk to someone (short version)");
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
        tui.tuiPrint("You do not have any item called " + item + " here.");
    }
    else {
        player.drop(*itemPtr);
        tui.tuiPrint("Dropped.");
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
    tui.tuiPrint(player.getFullLocationDescription());
}

void chosen::Game::cmdNorth() {
    movePlayer(NORTH);
}

void chosen::Game::cmdEast() {
    movePlayer(EAST);
}

void chosen::Game::cmdSouth() {
    movePlayer(SOUTH);
}

void chosen::Game::cmdWest() {
    movePlayer(WEST);
}

void chosen::Game::cmdUp() {
    movePlayer(UP);
}

void chosen::Game::cmdDown() {
    movePlayer(DOWN);
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
