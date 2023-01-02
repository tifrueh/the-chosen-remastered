// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022  Timo Früh
// Full copyright notice in src/main.cpp


#pragma once

#include <string>
#include <array>

namespace crsrc {
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
    const std::string swords_odd_demon_king_kill_txt = "You grip the sword hilts and draw the blades. An-Harat blocks your first thrust with ease and starts a vicious counterattack, aiming for your throat. The Sword of Dusk sweeps up, deflecting An-Harat's blade. But he keeps his balance and comes at you again. He pushes you back with a series of incredibly fast attacks, and you have to step back a few paces, all while blocking his slashes with both your swords. A shallow cut appears on your arm, seeping blood. Doubt enters your mind. Can you truly defeat this beast? You feel the swords in your hands becoming warmer and strength floods back into your tired arms. You push away all thoughts and launch an attack yourself. You lunge towards your enemy, the Sword of Dawn reaching for An-Harat's chest. He blocks your thrust, but you turn around and fight on, faster and faster, until your eyes can barely see your blades anymore. You feel your foe tiring, each of his moves becoming slower and less controlled. Finally, you spot an opening in An-Harat's defense and move in for the kill. The Sword of Dawn sinks into the Demon King's chest, his sword clatters to the ground, and you look into his eyes, their fire slowly fading.";
    const std::string cellar_txt = "You are in a damp cellar. It's cold, the walls are all made of grey rock, and it's generally rather unpleasant here. The only light is coming from a torch mounted to the north wall. You can also see the decaying body of a long dead ... thing? (it is definitely not human) chained to the east wall. That must be where the unbearable stench is coming from.";
    const std::string cellar_ladder_txt = "You are standing in a stairwell with rough stone walls covered in lichen and moss.";
    const std::string hall_txt = "You are now standing in a long hall, the ceiling of which you can barely see. There are many torches on every wall, flooding the vast room with light. The walls are ornately decorated and in the middle of the room you see a long table with many wooden chairs to each side of it. It seems as if someone was preparing a feast, for the table is set with many plates and cutlery. The only thing missing is the food.";
    const std::string east_hall_room_txt = "You are in a room east to the Hall, but there is nothing in here, except a torch, mounted to the north wall.";
    const std::string west_hall_room_txt = "You are in a room west to the Hall. It is a simple room, containing only a small round table with a candle on it and two chairs. But there is small square opening in the north wall, probably for food to be passed through from the room above with an elevator.";
    const std::string trophy_room_txt = "You are now standing in a room in which every wall is packed with shelves. On these shelves are trophies of polished gold, so many that you have to close your eyes first to get accustomed to the gleaming golden light they reflect. The only real light source is a lantern hanging in the middle of the ceiling.";
    const std::string ns_passageway_txt = "You are now in a narrow corridor oriented from north to south. On each wall is a row of torches filling the room with light.";
    const std::string staff_room_txt = "You are now standing in a small but cozy room containing a small table, two chairs and a double bed, covered with red and white sheets. You can also see a hearth fitted into the north wall. A fire has been carefully built, but not yet ignited. The only light is coming from a lantern standing on the table.";
    const std::string library_txt = "You are in a big library with a huge amount of bookshelves containing an uncountable amount of books. There are multiple big chandeliers hanging from the ceiling so that there is enough light for reading in even the remotest corner of the room. There is also a big desk with stacks of books packed on it, but there doesn't seem to be a librarian around.";
    const std::string library_entrance_txt = "You are now standing in an empty room. There is a sign on the north wall, upon which is written in huge ornate letters: \"Welcome to the great Library of His Majesty\" and just below a sticky note: \"John, for God's sake, bring back your books.\"";
    const std::string air_demon_kill_txt = "You can't reach the demon, as it is flying high above your head. It might have been beneficial to use a weapon with more range. The demon reaches out with its long claws plunges them into your chest.\nYou die ...";
}
