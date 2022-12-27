// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <ncurses.h>
#include <locale.h>
#include <string.h>
#include <string>
#include "tui.hpp"

ctui::TUI::TUI() {
    initscr();
    raw();
    noecho();
    curs_set(0);
    setlocale(LC_ALL, "");

    getmaxyx(stdscr, maxy, maxx);

    createBox(3, maxx, 0, 0);
    createBox(maxy - 6, maxx, 3, 0);
    createBox(3, maxx, maxy - 3, 0);

    locationWin = newwin(1, 40, 1, 2);
    wprintw(locationWin, "[LOCATION PLACEHOLDER]");
    wrefresh(locationWin);

    scoreWin = newwin(1, 10, 1, maxx - 26);
    wprintw(scoreWin, "SCORE: 000");
    wrefresh(scoreWin);

    movesWin = newwin(1, 12, 1, maxx - 14);
    wprintw(movesWin, "MOVES: 0000");
    wrefresh(movesWin);

    outWin = newwin(maxy - 8, maxx - 4, 4, 2);
    scrollok(outWin, TRUE);
    outMaxx = getmaxx(outWin);

    inWin = newwin(1, maxx - 2, maxy - 2, 1);
    keypad(inWin, TRUE);
    inMaxx = getmaxx(inWin);

    mvwprintw(inWin, 0, 1, ">");
    wmove(inWin, 0, 3);
    wrefresh(inWin);
}

ctui::TUI::~TUI() {
    endwin();
}

WINDOW *ctui::TUI::createBox(int height, int width, int yPos, int xPos) {
    WINDOW *localWin = newwin(height, width, yPos, xPos);
    box(localWin, 0, 0);

    wrefresh(localWin);

    return localWin;
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
    char *str = (char*) malloc(inMaxx * sizeof(char));

    curs_set(1);
    echo();
    mvwgetstr(inWin, 0, 3, str);
    noecho();
    curs_set(0);

    wmove(inWin, 0, 3);
    wclrtoeol(inWin);

    wrefresh(inWin);

    std::string out = str;

    free(str);

    return out;
}

std::string ctui::TUI::tuiInput(const std::string &prompt) {
    tuiPrint(prompt);
    std::string out = tuiInput();
    return out;
}
