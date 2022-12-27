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

    const char splashLineOne[] = "The Chosen";
    const char splashLineTwo[] = "At Night's End";

    mvprintw(maxy / 2, (maxx - strlen(splashLineOne)) / 2, splashLineOne);
    refresh();

    napms(1000);

    mvprintw(maxy / 2 + 1, (maxx - strlen(splashLineTwo)) / 2, splashLineTwo);
    refresh();

    napms(2000);

    createBox(3, maxx, 0, 0);
    createBox(maxy - 6, maxx, 3, 0);
    createBox(3, maxx, maxy - 3, 0);

    outWin = newwin(maxy - 8, maxx - 4, 4, 2);
    scrollok(outWin, TRUE);
    getmaxyx(outWin, outMaxy, outMaxx);

    inWin = newwin(1, maxx - 2, maxy - 2, 1);
    keypad(inWin, TRUE);
    getmaxyx(inWin, inMaxy, inMaxx);

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
    char *str = (char*) malloc(maxx * sizeof(char));

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
