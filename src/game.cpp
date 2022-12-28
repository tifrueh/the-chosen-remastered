// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <string>
#include "tui.hpp"
#include "customstring.hpp"
#include "parser.hpp"
#include "game.hpp"

void chosen::Game::gameloop() {
    ctui::TUI tui("[LOCATION PLACEHOLDER");
    std::string command;

    tui.tuiPrint("Welcome message\n"
                 "---------------\n"
                 "Lorem ipsum dolor sit amet, consectetur adipiscing elit, \n"
                 "sed do eiusmod tempor incididunt ut labore et dolore magna \n"
                 "aliqua. Volutpat maecenas volutpat blandit aliquam.\n"
                 );

    while (command != "exit" && command != "quit") {
        command = tui.tuiInput();
        cstr::trim(command);

        if (command != "") {
            tui.tuiPrint("> " + command + "\n\n");
        }

        cstr::to_lower(command);

        if (cprs::isCommand(command, "fight")) {
            tui.tuiPrint("fight command\n");
        }
        else if (cprs::isCommand(command, "talk to")) {
            tui.tuiPrint("talk to command");
        }
        else if (cprs::isCommand(command, "talk")) {
            tui.tuiPrint("talk command\n");
        }
        else if (cprs::isCommand(command, "take")) {
            tui.tuiPrint("take command");
        }
        else if (cprs::isCommand(command, "drop")) {
            tui.tuiPrint("drop command");
        }
    }
}
