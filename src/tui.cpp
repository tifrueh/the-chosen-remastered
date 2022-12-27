// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in main.cpp


#include <ncurses.h>
#include <locale.h>
#include <string.h>
#include <string>
#include "tui.hpp"
#include "customstring.hpp"

ctui::TUI::TUI(const std::string &initialLocation) {
    score = 0;
    moves = 0;

    initscr();
    raw();
    noecho();
    curs_set(0);
    setlocale(LC_ALL, "");

    getmaxyx(stdscr, maxy, maxx);

    initStatusBar(initialLocation);
    initOutWin();
    initInWin();
}

ctui::TUI::~TUI() {
    endwin();
}

void ctui::TUI::initStatusBar(const std::string &initialLocation) {
    const char *str = initialLocation.c_str();

    createBox(3, maxx, 0, 0);

    locationWin = newwin(1, 40, 1, 2);
    wprintw(locationWin, str);
    wrefresh(locationWin);

    scoreWin = newwin(1, 10, 1, maxx - 26);
    wprintw(scoreWin, "SCORE: 000");
    wrefresh(scoreWin);

    movesWin = newwin(1, 12, 1, maxx - 14);
    wprintw(movesWin, "MOVES: 0000");
    wrefresh(movesWin);
}

void ctui::TUI::initOutWin() {
    createBox(maxy - 6, maxx, 3, 0);

    outWin = newwin(maxy - 8, maxx - 4, 4, 2);
    scrollok(outWin, TRUE);
    outMaxx = getmaxx(outWin);
}

void ctui::TUI::initInWin() {
    createBox(3, maxx, maxy - 3, 0);

    inWin = newwin(1, maxx - 2, maxy - 2, 1);
    keypad(inWin, TRUE);
    inMaxx = getmaxx(inWin);

    mvwprintw(inWin, 0, 1, ">");
    wmove(inWin, 0, 3);
    wrefresh(inWin);
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

void ctui::TUI::setLocation(const std::string &location) {
    const char *str = location.c_str();

    wclear(locationWin);
    wprintw(locationWin, str);
}

void ctui::TUI::incrementScore() {
    score += 1;
    std::string sScore = cstr::int_to_string(score, 3);
    const char *csScore = sScore.c_str();
    mvwprintw(scoreWin, 0, 7, csScore);
    wrefresh(scoreWin);
}

void ctui::TUI::incrementMoves() {
    moves += 1;
    std::string sMoves = cstr::int_to_string(moves, 4);
    const char *csMoves = sMoves.c_str();
    mvwprintw(movesWin, 0, 7, csMoves);
    wrefresh(movesWin);
}
