// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <array>

namespace crsrc {
    const std::string air_demon_kill_txt = "You can't reach the demon, as it is flying high above your head. It might have been beneficial to use a weapon with more range. The demon reaches out with its long claws plunges them into your chest.\nYou die ...";
    const std::string cellar_txt = "You are in a damp cellar. It's cold, the walls are all made of grey rock, and it's generally rather unpleasant here. The only light is coming from a torch mounted to the north wall. You can also see the decaying body of a long dead ... thing? (it is definitely not human) chained to the east wall. That must be where the unbearable stench is coming from.";
    const std::array<std::string, 11> welcome_message_txt = {
        "You slowly open your eyes and wake up. You can't remember anything.",
        "No, wait, there is something ...",
        "Suddenly, a clear thought springs into your mind.",
        "Is it a memory? A vision? You speak it out loud:",
        "",
        "Greetings, adventurer. Are you aware of the difficulty of the task ahead? I suppose it is not so, for you would not be here if it were. So let me tell about your Quest: You must find the legendary Swords of Dusk and Dawn in order to kill the Demon King and thus finally end his cruel reign and free the land from the clutches of his demons. Fare thee well!",
        "",
        "Not a memory, then, but a message.",
        "You once again try to think back with all force you can muster ...",
        "And a name pops into your memory. Anyone's name?",
        "No, your name ... Must be ..."
    };
}
