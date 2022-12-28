// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include "tui.hpp"
#include "customstring.hpp"
#include "parser.hpp"
#include "game.hpp"

void chosen::Game::gameloop() {
    ctui::TUI tui("[---------LOCATION PLACEHOLDER---------]");
    std::string command;

    tui.tuiPrint("Welcome message\n"
                 "---------------\n"
                 "Lorem ipsum dolor sit amet, consectetur adipiscing elit, \n"
                 "sed do eiusmod tempor incididunt ut labore et dolore magna \n"
                 "aliqua. Volutpat maecenas volutpat blandit aliquam.\n"
                 );

    while (command != "exit" && command != "quit") {
        command = tui.tuiInput();
        tui.incrementMoves();
        cstr::trim(command);
        std::string errorMessage = "I do not know what you meant by " + command + ".\n";

        tui.tuiPrint("\n> " + command + "\n");

        cstr::to_lower(command);

        if (cprs::isCommand(command, "talk to")) {
            tui.tuiPrint("cmd: talk to someone\n");
        }
        else if (cprs::isCommand(command, "talk")) {
            tui.tuiPrint("cmd: talk to someone (short version)\n");
        }
        else if (cprs::isCommand(command, "fight")) {
            tui.tuiPrint("cmd: fight someone\n");
        }
        else if (cprs::isCommand(command, "take")) {
            tui.tuiPrint("cmd: take something\n");
        }
        else if (cprs::isCommand(command, "drop")) {
            tui.tuiPrint("cmd: drop something\n");
        }
        else if (cprs::isCommand(command, "hug")) {
            tui.tuiPrint("cmd: hug someone\n");
        }
        else if (cprs::isCommand(command, "open")) {
            tui.tuiPrint("cmd: open a door\n");
        }
        else if (cprs::isCommand(command, "close")) {
            tui.tuiPrint("cmd: close a door\n");
        }
        else if (cprs::isCommand(command, "lock")) {
            tui.tuiPrint("cmd: lock a door\n");
        }
        else if (cprs::isCommand(command, "unlock")) {
            tui.tuiPrint("cmd: unlock a door\n");
        }
        else if (command == "north") {
            tui.tuiPrint("cmd: move north\n");
        }
        else if (command == "east") {
            tui.tuiPrint("cmd: move east\n");
        }
        else if (command == "south") {
            tui.tuiPrint("cmd: move south\n");
        }
        else if (command == "west") {
            tui.tuiPrint("cmd: move west\n");
        }
        else if (command == "up") {
            tui.tuiPrint("cmd: move up\n");
        }
        else if (command == "down") {
            tui.tuiPrint("cmd: move down\n");
        }
        else if (command == "scream") {
            tui.tuiPrint("cmd: scream (stop it ... get some help)\n");
        }
        else if (command == "help") {
            tui.tuiPrint("cmd: help\n");
        }
        else if (command == "inventory" || command == "i") {
            tui.tuiPrint("cmd: open your inventory\n");
        }
        else if (command == "look" || command == "look around" || command == "l") {
            tui.tuiPrint("cmd: look around\n");
        }
        else if (command == "exit" || command == "quit") {
            std::string affirm = tui.tuiInput("Do you really wish to leave the game? (y is affermative)\n");
            if (affirm != "y") {
                command = "";
            }
            else {
                tui.waitForInput("\n[Hit any key to exit]");
            }
        }
        else if (command == "") {
            tui.tuiPrint("I beg your pardon?\n");
        }
        else {
            tui.tuiPrint(errorMessage);
        }
    }
}
