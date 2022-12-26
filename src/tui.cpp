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

    getmaxyx(stdscr, maxy, maxx);

    ctui::createBox(maxy - 7, maxx - 4, 2, 2);
    ctui::createBox(3, maxx - 4, maxy - 5, 2);

    outWin = newwin(maxy - 9, maxx - 7, 3, 4);
    scrollok(outWin, TRUE);
    getmaxyx(outWin, outMaxy, outMaxx);

    inWin = newwin(1, maxx - 6, maxy - 4, 3);
    keypad(inWin, TRUE);
    getmaxyx(inWin, inMaxy, inMaxx);

    mvwprintw(inWin, 0, 1, ">");
    wmove(inWin, 0, 3);
    wrefresh(inWin);
}

ctui::TUI::~TUI() {
    endwin();
}

void ctui::TUI::tuiNapMs(const int &ms) {
    napms(ms);
}

void ctui::TUI::tuiPrint(const std::string &input) {
    const char *str = input.c_str();
    wprintw(outWin, str);
    wrefresh(outWin);
}

std::string ctui::TUI::tuiInput() {
    char str[inMaxx] = "";
    ctui::textField(inWin, 0, 3, inMaxx, str);

    std::string out = str;

    return out;
}

std::string ctui::TUI::tuiInput(const std::string &prompt) {
    tuiPrint(prompt);
    std::string out = tuiInput();
    return out;
}


void ctui::textField(WINDOW* win, int yPos, int xPos, int yLen, char* out) {
    
    curs_set(1);
    echo();
    mvwgetstr(win, yPos, xPos, out);
    noecho();
    curs_set(0);

    wmove(win, 0, 3);
    wclrtoeol(win);

    wrefresh(win);
}

WINDOW *ctui::createBox(int height, int width, int yPos, int xPos) {
    WINDOW *localWin = newwin(height, width, yPos, xPos);
    box(localWin, 0, 0);

    wrefresh(localWin);

    return localWin;
}
