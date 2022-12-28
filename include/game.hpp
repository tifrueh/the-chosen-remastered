// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

namespace chosen {
    class Game {
        private:
            int state;
            int score;
            int moves;

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
            void cmdSough();
            void cmdWest();
            void cmdUp();
            void cmdDown();
            void cmdScream();
            void cmdHelp();
            void cmdInventory();
            void cmdLook();
            void cmdExit();

        public:
            Game();
            void gameloop();
    };
}
