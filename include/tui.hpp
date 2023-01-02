// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <ncurses.h>
#include <string>
#include <array>
#include <vector>

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

            void init(const std::string &initialLocation);
            void initStatusBar(const std::string &initialLocation);
            void initOutWin();
            void initInWin();
            void mvGetStr(const int &y, const int &x, char *str);

            WINDOW *createBox(int height, int width, int yPos, int xPos);
        
        public:
            TUI(const std::string &initialLocation);
            TUI();
            ~TUI();
            void tuiNapMs(const int &ms);
            void waitForInput();
            void waitForInput(const std::string &prompt);
            void tuiPrint(const std::string &input);
            void tuiPrint(const std::vector<std::string> &input);
            void tuiPrintNewline();
            void setLocation(const std::string &location);
            void updateScore(const int &score);
            void updateMoves(const int &moves);
            void clear();
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
