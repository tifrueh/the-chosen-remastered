// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include "tui.hpp"
#include "customstring.hpp"
#include "parser.hpp"
#include "resources.hpp"
#include "game.hpp"

chosen::Game::Game() {
    state = 0;
    score = 0;
    moves = 0;

    hall.setDescription(crsrc::hall_txt);
    hall.addDoor(hallEastHallDoor, EAST);

    eastHallRoom.setDescription(crsrc::east_hall_room_txt);
    eastHallRoom.addDoor(hallEastHallDoor, WEST);
}

void chosen::Game::gameloop() {
    std::string command;

    tui.setLocation("Unknown location");

    tui.tuiPrint<11>(crsrc::welcome_message_txt);

    player.setName(tui.tuiInput("\nWhat is your name?"));

    tui.tuiPrint("");

    player.setLocation(hall);
    tui.setLocation(player.getLocationName());

    tui.tuiPrint(player.getFullLocationDescription());

    while (state == 0) {
        command = tui.tuiInput();
        cstr::trim(command);
        std::string errorMessage = "I do not know what you meant by " + command + ".";

        tui.tuiPrint("\n> " + command);

        cstr::to_lower(command);

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
            cmdTake();
        }
        else if (cprs::isCommand(command, "drop")) {
            cmdDrop();
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

void chosen::Game::movePlayer(const int &direction) {
    if (player.getLocation()->hasDoorToDirection(direction)) {
        player.move(direction);
        tui.tuiPrint(player.getFullLocationDescription());
    }
    else {
        tui.tuiPrint("You run head first into a wall and realize: You can't go that way.");
    }
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

void chosen::Game::cmdTake() {
    tui.tuiPrint("cmd: take something");
}

void chosen::Game::cmdDrop() {
    tui.tuiPrint("cmd: drop something");
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
    tui.tuiPrint("cmd: move up");
}

void chosen::Game::cmdDown() {
    tui.tuiPrint("cmd: move down");
}

void chosen::Game::cmdScream() {
    tui.tuiPrint("cmd: scream (stop it ... get some help)");
}

void chosen::Game::cmdHelp() {
    tui.tuiPrint("cmd: help");
}

void chosen::Game::cmdInventory() {
    tui.tuiPrint("cmd: open your inventory");
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
