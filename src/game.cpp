// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include "tui.hpp"
#include "customstring.hpp"
#include "parser.hpp"
#include "resources.hpp"
#include "game.hpp"

void chosen::Game::gameloop() {
    ctui::TUI tui("[---------LOCATION PLACEHOLDER---------]");
    std::string command;

    tui.tuiPrint<11>(crsrc::welcome_message_txt);

    while (command != "exit" && command != "quit") {
        command = tui.tuiInput();
        tui.incrementMoves();
        cstr::trim(command);
        std::string errorMessage = "I do not know what you meant by " + command + ".";

        tui.tuiPrint("\n> " + command);

        cstr::to_lower(command);

        if (cprs::isCommand(command, "talk to")) {
            tui.tuiPrint("cmd: talk to someone");
        }
        else if (cprs::isCommand(command, "talk")) {
            tui.tuiPrint("cmd: talk to someone (short version)");
        }
        else if (cprs::isCommand(command, "fight")) {
            tui.tuiPrint("cmd: fight someone");
        }
        else if (cprs::isCommand(command, "take")) {
            tui.tuiPrint("cmd: take something");
        }
        else if (cprs::isCommand(command, "drop")) {
            tui.tuiPrint("cmd: drop something");
        }
        else if (cprs::isCommand(command, "hug")) {
            tui.tuiPrint("cmd: hug someone");
        }
        else if (cprs::isCommand(command, "open")) {
            tui.tuiPrint("cmd: open a door");
        }
        else if (cprs::isCommand(command, "close")) {
            tui.tuiPrint("cmd: close a door");
        }
        else if (cprs::isCommand(command, "lock")) {
            tui.tuiPrint("cmd: lock a door");
        }
        else if (cprs::isCommand(command, "unlock")) {
            tui.tuiPrint("cmd: unlock a door");
        }
        else if (command == "north") {
            tui.tuiPrint("cmd: move north");
        }
        else if (command == "east") {
            tui.tuiPrint("cmd: move east");
        }
        else if (command == "south") {
            tui.tuiPrint("cmd: move south");
        }
        else if (command == "west") {
            tui.tuiPrint("cmd: move west");
        }
        else if (command == "up") {
            tui.tuiPrint("cmd: move up");
        }
        else if (command == "down") {
            tui.tuiPrint("cmd: move down");
        }
        else if (command == "scream") {
            tui.tuiPrint("cmd: scream (stop it ... get some help)");
        }
        else if (command == "help") {
            tui.tuiPrint("cmd: help");
        }
        else if (command == "inventory" || command == "i") {
            tui.tuiPrint("cmd: open your inventory");
        }
        else if (command == "look" || command == "look around" || command == "l") {
            tui.tuiPrint("cmd: look around");
        }
        else if (command == "exit" || command == "quit") {
            std::string affirm = tui.tuiInput("Do you really wish to leave the game? (y is affermative)");
            if (affirm != "y") {
                command = "";
            }
            else {
                tui.waitForInput("\n[Hit any key to exit]");
            }
        }
        else if (command == "") {
            tui.tuiPrint("I beg your pardon?");
        }
        else {
            tui.tuiPrint(errorMessage);
        }
    }
}
