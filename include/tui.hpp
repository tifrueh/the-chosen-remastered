// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <ncurses.h>
#include <string>
#include <array>

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
            int score;
            int moves;

            void initStatusBar(const std::string &initialLocation);
            void initOutWin();
            void initInWin();

            WINDOW *createBox(int height, int width, int yPos, int xPos);
        
        public:
            TUI(const std::string &initialLocation);
            ~TUI();
            void tuiNapMs(const int &ms);
            void waitForInput();
            void waitForInput(const std::string &prompt);
            void tuiPrint(const std::string &input);
            void setLocation(const std::string &location);
            void incrementScore();
            void incrementMoves();
            std::string tuiInput();
            std::string tuiInput(const std::string &prompt);

            template <size_t N>
            void tuiPrint(const std::array<std::string, N> &input);
    };

}

template <size_t N>
void ctui::TUI::tuiPrint(const std::array<std::string, N> &input) {
    for (std::string string : input) {
        tuiPrint(string);
    }
}
