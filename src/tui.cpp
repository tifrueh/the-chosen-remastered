// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <ncurses.h>
#include <string>
#include "tui.hpp"

ctui::TUI::TUI() {
    initscr();
    raw();
    noecho();
    curs_set(0);

    int maxy, maxx;
    getmaxyx(stdscr, maxy, maxx);

    ctui::createBox(maxy - 7, maxx - 4, 2, 2);
    ctui::createBox(3, maxx - 4, maxy - 5, 2);

    outWin = newwin(maxy - 9, maxx - 7, 3, 4);
    scrollok(outWin, TRUE);

    inWin = newwin(1, maxx - 6, maxy - 4, 3);
    keypad(inWin, TRUE);

    mvwprintw(inWin, 0, 1, ">");
    wmove(inWin, 0, 3);
    wrefresh(inWin);
}

ctui::TUI::~TUI() {
    endwin();
}

void ctui::TUI::tuiNapMs(int ms) {
    napms(ms);
}

void ctui::TUI::cPrint(std::string input) {
    const char *str = input.c_str();
    wprintw(outWin, str);
    wrefresh(outWin);
}

void ctui::textField(WINDOW* win, int yPos, int xPos, int yLen, char* out) {
    
    curs_set(1);
    echo();
    mvwgetstr(win, yPos, xPos, out);
    noecho();
    curs_set(0);

    wmove(win, 0, 3);
    wclrtoeol(win);
}

WINDOW *ctui::createBox(int height, int width, int yPos, int xPos) {
    WINDOW *localWin = newwin(height, width, yPos, xPos);
    box(localWin, 0, 0);

    wrefresh(localWin);

    return localWin;
}
