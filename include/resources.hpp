// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <array>
#include <vector>

namespace crsrc {
    extern const std::string version;
    extern const std::array<std::string, 6> welcomeMessage;
    extern const std::array<std::string, 11> intro;
    extern const std::string victoryMessage;
    extern const std::string cellarDesc;
    extern const std::string cellarLadderDesc;
    extern const std::string hallDesc;
    extern const std::string eastHallRoomDesc;
    extern const std::string westHallRoomDesc;
    extern const std::string trophyRoomDesc;
    extern const std::string nsPassagewayDesc;
    extern const std::string staffRoomDesc;
    extern const std::string libraryDesc;
    extern const std::string libraryEntranceDesc;
    extern const std::string throneEntranceDesc;
    extern const std::string hiddenRoomDesc;
    extern const std::string throneRoomDesc;
    extern const std::string longswordDesc;
    extern const std::string longswordExDesc;
    extern const std::string longswordInitDesc;
    extern const std::string crossbowDesc;
    extern const std::string crossbowExDesc;
    extern const std::string crossbowInitDesc;
    extern const std::string swordsOddDescription;
    extern const std::string swordsOddExDescription;
    extern const std::string swordsOddInitDescription;
    extern const std::string swordsOddReqUnmetMessage;
    extern const std::string fireWandDesc;
    extern const std::string fireWandExDesc;
    extern const std::string fireWandInitDesc;
    extern const std::string holyWaterDesc;
    extern const std::string holyWaterExDesc;
    extern const std::string holyWaterInitDesc;
    extern const std::string strangerDesc;
    extern const std::vector<std::string> strangerConversation;
    extern const std::string strangerDefVictoryMsg;
    extern const std::string strangerDefDeathMsg;
    extern const std::string defeatStrangerLongsword;
    extern const std::string warrioressDesc;
    extern const std::vector<std::string> warrioressConversation;
    extern const std::string elliotDesc;
    extern std::vector<std::string> elliotConversation;
    extern const std::string elliotHug;
    extern const std::string elliotDefDeathMsg;
    extern const std::string defeatElliotWater;
    extern const std::string hagDesc;
    extern const std::vector<std::string> hagConversation;
    extern const std::string defeatHagWater;
    extern const std::string scholarDesc;
    extern const std::vector<std::string> scholarConversation;
    extern const std::string defeatScholarWater;
    extern const std::string demonKingDesc;
    extern const std::vector<std::string> demonKingConversation;
    extern const std::string demonKingHugMessage;
    extern const std::string demonKingDefVictoryMsg;
    extern const std::string victoryDemonKingSwords;
    extern const std::string mandrakDesc;
    extern const std::vector<std::string> mandrakConversation;
    extern const std::string mandrakDefVictoryMsg;
    extern const std::string victoryMandrakSwords;
    extern const std::vector<std::string> demonConversation;
    extern const std::string demonHugMessage;
    extern const std::string fireDemonDesc;
    extern const std::string fireDemonDefVictoryMsg;
    extern const std::string victoryFireDemonHolyWater;
    extern const std::string defeatFireDemonWand;
    extern const std::string waterDemonDesc;
    extern const std::string waterDemonDefVictoryMsg;
    extern const std::string victoryWaterDemonWand;
    extern const std::string defeatWaterDemonWater;
    extern const std::string airDemonDesc;
    extern const std::string airDemonDefVictoryMsg;
    extern const std::string victoryAirDemonCrossbow;
    extern const std::string earthDemonDesc;
    extern const std::string earthDemonDefVictoryMsg;
    extern const std::string victoryEarthDemonCrossbow;
    extern const std::vector<std::string> help;
}
