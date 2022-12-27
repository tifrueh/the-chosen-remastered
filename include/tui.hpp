// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <ncurses.h>
#include <string>

namespace ctui {

    class TUI {

        private:
            WINDOW *locationWin;
            WINDOW *scoreWin;
            WINDOW *movesWin;
            WINDOW *outWin;
            WINDOW *inWin;
            int maxy, maxx;
            int inMaxx;
            int outMaxx;

            WINDOW *createBox(int height, int width, int yPos, int xPos);
        
        public:
            TUI();
            ~TUI();
            void tuiNapMs(const int &ms);
            void tuiPrint(const std::string &input);
            std::string tuiInput();
            std::string tuiInput(const std::string &prompt);
    };

}
