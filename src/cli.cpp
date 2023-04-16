// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in main.cpp

#include <string>
#include "cli.hpp"

bool ccli::hasCliArg(int argc, char* argv[], cliArg argument) {
    bool argFound = false;

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], argument.shortArg) == 0 || strcmp(argv[i], argument.longArg) == 0) {
            argFound = true;
        } else {
            argFound = false;
        }
    }

    return argFound;
}
