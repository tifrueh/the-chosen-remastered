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
            int score;
            int moves;
            bool running;

            ctui::TUI tui;

            Player player;

            Room cellar = {"cellar", "Cellar"};
            Room cellarLadderRoom = {"cellarLadder", "Ladder to the Cellar"};
            Room hall = {"hall", "The Hall"};
            Room westHallRoom = {"westHallRoom", "Room West to the Hall"};
            Room trophyRoom = {"trophyRoom", "Trophy Room"};
            Room nsPassageway = {"nsPassageway", "N/S Passageway"};
            Room staffRoom = {"staffRoom", "Staff Room"};
            Room library = {"library", "The Library"};
            Room libraryEntrance = {"libraryEntrance", "Library Entrance"};
            Room eastHallRoom = {"eastHallRoom", "Room East to the Hall"};
            Room throneEntrance = {"throneEntrance", "Entrance to the Throne Room"};
            Room hiddenRoom = {"hiddenRoom", "Hidden Room"};
            Room throneRoom = {"throneRoom", "Throne Room"};

            Link cellarLadder = {"cellarLadder", true};
            Link ladderHallDoor = {"ladderHallDoor", true};
            Link hallWestHallDoor = {"hallWestHallDoor", true};
            Link westHallTrophyDoor = {"westHallTrophyDoor", true};
            Link trophyNSPassagewayDoor = {"trophyNSPassagewayDoor", true};
            Link nsPassagewayStaffDoor = {"nsPassagewayStaffDoor", true};
            Link staffLibraryDoor = {"staffLibraryDoor", true};
            Link libraryLibraryEntranceDoor {"libraryLibraryEntranceDoor", true};
            Link libraryEntranceHallDoor = {"libraryEntranceHallDoor", true};
            Link hallEastHallDoor = {"hallEastHallDoor", true};
            Link eastHallThroneEntranceDoor = {"eastHallThroneEntranceDoor", true};
            Link hiddenRoomLink = {"hiddenRoomLink", false};
            Link throneDoor = {"throneDoor", true};

            Item longsword = {"longsword", "a", "sword"};
            Item crossbow = {"crossbow", "a", "crossbow"};
            Item swordsODD = {"swordsODD", "the", "Swords of Dusk and Dawn"};
            Item fireWand = {"fireWand", "a", "wand of fire"};
            Item holyWater = {"holyWater", "a", "bottle of holy water"};

            NPC stranger = {"stranger", "a", "stranger"};
            NPC elliot = {"elliot", "", "Elliot"};
            NPC hag = {"hag", "an", "old hag"};
            NPC scholar = {"scholar", "a", "scholar"};

            Enemy demonKing = {"demonKing", "", "An-Harat"};

            void initWorld();
            void initLoop();
            void endLoop();
            void endGame();

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
