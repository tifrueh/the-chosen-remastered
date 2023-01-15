// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include "world.hpp"
#include "player.hpp"
#include "tui.hpp"
#include "item.hpp"
#include "character.hpp"

namespace chosen {
    class Game {
        private:
            int state;
            int score;
            int moves;

            ctui::TUI tui;

            chosen::Player player;

            chosen::Room cellar = {"cellar", "Cellar"};
            chosen::Room cellarLadderRoom = {"cellarLadder", "Ladder to the Cellar"};
            chosen::Room hall = {"hall", "The Hall"};
            chosen::Room westHallRoom = {"westHallRoom", "Room West to the Hall"};
            chosen::Room trophyRoom = {"trophyRoom", "Trophy Room"};
            chosen::Room nsPassageway = {"nsPassageway", "N/S Passageway"};
            chosen::Room staffRoom = {"staffRoom", "Staff Room"};
            chosen::Room library = {"library", "The Library"};
            chosen::Room libraryEntrance = {"libraryEntrance", "Library Entrance"};
            chosen::Room eastHallRoom = {"eastHallRoom", "Room East to the Hall"};
            chosen::Room throneEntrance = {"throneEntrance", "Entrance to the Throne Room"};
            chosen::Room hiddenRoom = {"hiddenRoom", "Hidden Room"};
            chosen::Room throneRoom = {"throneRoom", "Throne Room"};

            chosen::Link cellarLadder = {"cellarLadder", true};
            chosen::Link ladderHallDoor = {"ladderHallDoor", true};
            chosen::Link hallWestHallDoor = {"hallWestHallDoor", true};
            chosen::Link westHallTrophyDoor = {"westHallTrophyDoor", true};
            chosen::Link trophyNSPassagewayDoor = {"trophyNSPassagewayDoor", true};
            chosen::Link nsPassagewayStaffDoor = {"nsPassagewayStaffDoor", true};
            chosen::Link staffLibraryDoor = {"staffLibraryDoor", true};
            chosen::Link libraryLibraryEntranceDoor {"libraryLibraryEntranceDoor", true};
            chosen::Link libraryEntranceHallDoor = {"libraryEntranceHallDoor", true};
            chosen::Link hallEastHallDoor = {"hallEastHallDoor", true};
            chosen::Link eastHallThroneEntranceDoor = {"eastHallThroneEntranceDoor", true};
            chosen::Link hiddenRoomLink = {"hiddenRoomLink", false};
            chosen::Link throneDoor = {"throneDoor", true};

            chosen::Item longsword = {"longsword", "a", "sword"};
            chosen::Item crossbow = {"crossbow", "a", "crossbow"};
            chosen::Item swordsODD = {"swordsODD", "the", "Swords of Dusk and Dawn"};
            chosen::Item fireWand = {"fireWand", "a", "wand of fire"};
            chosen::Item holyWater = {"holyWater", "a", "bottle of holy water"};

            chosen::Character stranger = {"stranger", "a", "stranger"};
            chosen::Character elliot = {"elliot", "", "Elliot"};
            chosen::Character hag = {"hag", "an", "old hag"};
            chosen::Character scholar = {"scholar", "a", "scholar"};

            void initWorld();
            void initLoop();

            void cmdTalk(std::string character);
            void cmdFight(std::string character, std::string item);
            void cmdTake(std::string item);
            void cmdDrop(std::string item);
            void cmdExamine(std::string item);
            void cmdHug(std::string character);
            void cmdOpen();
            void cmdClose();
            void cmdLock();
            void cmdUnlock();

            void movePlayer(const int &direction);
            void cmdGo(std::string direction);
            void cmdClimb(std::string direction);

            void cmdScream();
            void cmdHelp();
            void cmdInventory();
            void cmdLook();
            void cmdClear();
            void cmdExit();

        public:
            Game();
            void gameloop();
    };
}
