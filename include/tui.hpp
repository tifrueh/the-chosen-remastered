// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <ncurses.h>
#include <string>

namespace ctui {

    class TUI {

        private:
            WINDOW *outWin;
            WINDOW *inWin;
            int maxy, maxx;
            int inMaxy, inMaxx;
            int outMaxy, outMaxx;
        
        public:
            TUI();
            ~TUI();
            void tuiNapMs(const int &ms);
            void tuiPrint(const std::string &input);
            std::string tuiInput();
            std::string tuiInput(const std::string &prompt);
    };

    void textField(WINDOW* win, int yPos, int xPos, int yLen, char* out);
    WINDOW *createBox(int height, int width, int yPos, int xPos);

}
