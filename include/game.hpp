// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include "world.hpp"
#include "player.hpp"
#include "tui.hpp"

namespace chosen {
    class Game {
        private:
            int state;
            int score;
            int moves;

            ctui::TUI tui;

            chosen::Player player;

            chosen::Room hall = {"hall", "The Hall"};
            chosen::Room eastHallRoom = {"eastHallRoom", "Room East to the Hall"};

            chosen::Door hallEastHallDoor = {"hallEastHallDoor"};

            void cmdTalkTo();
            void cmdTalk();
            void cmdFight();
            void cmdTake();
            void cmdDrop();
            void cmdHug();
            void cmdOpen();
            void cmdClose();
            void cmdLock();
            void cmdUnlock();
            void cmdNorth();
            void cmdEast();
            void cmdSouth();
            void cmdWest();
            void cmdUp();
            void cmdDown();
            void cmdScream();
            void cmdHelp();
            void cmdInventory();
            void cmdLook();
            void cmdClear();
            void cmdExit();

            void movePlayer(const int &direction);

        public:
            Game();
            void gameloop();
    };
}
