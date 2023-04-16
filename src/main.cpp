// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <iostream>
#include <cstring>
#include <algorithm>
#include "resources.hpp"
#include "cli.hpp"
#include "game.hpp"

int main(int argc, char *argv[]) {
    ccli::cliArg version;
    version.shortArg = "-v";
    version.longArg = "--version";

    ccli::cliArg help;
    help.shortArg = "-h";
    help.longArg = "--help";

    bool cliArgVersion = ccli::hasCliArg(argc, argv, version);
    bool cliArgHelp = ccli::hasCliArg(argc, argv, help);

    if (cliArgVersion) {
        std::cout << crsrc::version << std::endl;
    }
    else if (cliArgHelp) {
        std::cout << crsrc::cliHelp << std::endl;
    } 
    else {
        chosen::Game theChosen;
        theChosen.gameloop();
    }
}
