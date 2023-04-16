// the-chosen-remastered: A short ZORK-like text adventure
// Copyright (C) 2022-2023 Timo Früh
// Full copyright notice in main.cpp

#include <string>
#include <array>
#include <vector>
#include "resources.hpp"

const std::string crsrc::version = "1.0.0";
const std::array<std::string, 6> crsrc::welcomeMessage = {
    "The Chosen: At Night's End (Remastered)",
    "Revision " + version,
    "Copyright (C) 2022-2023 Timo Frueh",
    "This program comes with ABSOLUTELY NO WARRANTY.",
    "This is free software, and you are welcome to redistribute it under certain conditions.",
    "See the GNU General Public License (GPL-3.0) for more details."
};
const std::array<std::string, 11> crsrc::intro = {
    "You slowly open your eyes and wake up. You can't remember anything.",
    "No, wait, there is something ...",
    "Suddenly, a clear thought springs into your mind.",
    "Is it a memory? A vision? You speak it out loud:",
    " ",
    "Greetings, adventurer. Are you aware of the difficulty of the task ahead? I suppose it is not so, for you would not be here if it were. So let me tell about your Quest: You must find the legendary Swords of Dusk and Dawn in order to kill the Demon King and thus finally end his cruel reign and free the land from the clutches of his demons. Fare thee well!",
    " ",
    "Not a memory, then, but a message.",
    "You once again try to think back with all force you can muster ...",
    "And a name pops into your memory. Anyone's name?",
    "No, your name ... Must be ..."
};
const std::string crsrc::victoryMessage = "Congratulations! You have been victorious and thereby beaten the game!";
const std::string crsrc::cellarDesc = "You are in a damp cellar. It's cold, the walls are all made of grey rock, and it's generally rather unpleasant here. The only light is coming from a torch mounted to the north wall. You can also see the decaying body of a long dead ... thing? (it is definitely not human) chained to the east wall. That must be where the unbearable stench is coming from.";
const std::string crsrc::cellarLadderDesc = "You are standing in a stairwell with rough stone walls covered in lichen and moss.";
const std::string crsrc::hallDesc = "You are now standing in a long hall, the ceiling of which you can barely see. There are many torches on every wall, flooding the vast room with light. The walls are ornately decorated and in the middle of the room you see a long table with many wooden chairs to each side of it. It seems as if someone was preparing a feast, for the table is set with many plates and cutlery. The only thing missing is the food.";
const std::string crsrc::eastHallRoomDesc = "You are in a room east to the Hall, but there is nothing in here, except a torch, mounted to the north wall.";
const std::string crsrc::westHallRoomDesc = "You are in a room west to the Hall. It is a simple room, containing only a small round table with a candle on it and two chairs. But there is small square opening in the north wall, probably for food to be passed through from the room above with an elevator.";
const std::string crsrc::trophyRoomDesc = "You are now standing in a room in which every wall is packed with shelves. On these shelves are trophies of polished gold, so many that you have to close your eyes first to get accustomed to the gleaming golden light they reflect. The only real light source is a lantern hanging in the middle of the ceiling.";
const std::string crsrc::nsPassagewayDesc = "You are now in a narrow corridor oriented from north to south. On each wall is a row of torches filling the room with light.";
const std::string crsrc::staffRoomDesc = "You are now standing in a small but cozy room containing a small table, two chairs and a double bed, covered with red and white sheets. You can also see a hearth fitted into the north wall. A fire has been carefully built, but not yet ignited. The only light is coming from a lantern standing on the table.";
const std::string crsrc::libraryDesc = "You are in a big library with a huge amount of bookshelves containing an uncountable amount of books. There are multiple big chandeliers hanging from the ceiling so that there is enough light for reading in even the remotest corner of the room. There is also a big desk with stacks of books packed on it, but there doesn't seem to be a librarian around.";
const std::string crsrc::libraryEntranceDesc = "You are now standing in an empty room. There is a sign on the north wall, upon which is written in huge ornate letters: \"Welcome to the great Library of His Majesty\" and just below a sticky note: \"John, for God's sake, bring back your books.\"";
const std::string crsrc::throneEntranceDesc = "You are now standing in a big, decorated room. There is a sign on the north wall, upon which is written in big, golden letters: \"Entrance to the Throne Room of His Majesty\". Light comes from three torches, one on each wall.";
const std::string crsrc::hiddenRoomDesc = "You are standing in a simple square room with wooden walls and a single lantern hanging from the ceiling. In the center of the room stands an altar and a case rests on top of it.";
const std::string crsrc::throneRoomDesc = "You are in a magnificent throne room. Everywhere you look you see nothing but gold, red and purple velvet and in the center of it all you see an indescribably marvellous throne, rising upon marble steps, carefully crafted by the most skillful architects in the kingdom.";
const std::string crsrc::longswordDesc = "A simple sword is lying on the floor.";
const std::string crsrc::longswordExDesc = "You notice that the sword is glowing faintly, indicating that a spell has been cast on it.";
const std::string crsrc::longswordInitDesc = "Beside the rotting corpse you notice a sword, placed just where the reach of the chained thing must have ended when it was still alive. Quite cruel, if you think about it.";
const std::string crsrc::crossbowDesc = "A double-winged crossbow is lying on the floor.";
const std::string crsrc::crossbowExDesc = "The crossbow seems quite small for a weapon of its kind, but it looks magical, probably enchanted to shoot infinite bolts.";
const std::string crsrc::crossbowInitDesc = "On one of the shelves, beside a particularly shiny goblet, lies a double-winged crossbow.";
const std::string crsrc::swordsOddDescription = "The Swords of Dusk and Dawn are lying on the floor, both glowing faintly.";
const std::string crsrc::swordsOddExDescription = "You hold both swords closer to your eyes and below the silver glow of Dusk and the crimson one of Dawn, you notice a multitude of runes, engraved in both blades. You cannot decipher them, however.";
const std::string crsrc::swordsOddInitDescription = "Inside of the case lie the Swords of Dusk and Dawn, both shining brilliantly, Dusk silver and Dawn crimson.";
const std::string crsrc::swordsOddReqUnmetMessage = "As you try to swing the Swords, they become increasingly heavy, compromising your balance. It seems you are not yet worthy of them.";
const std::string crsrc::fireWandDesc = "A wand of fire is lying on the floor.";
const std::string crsrc::fireWandExDesc = "As you trace your finger over the wood, the runes light up in a fiery glow.";
const std::string crsrc::fireWandInitDesc = "On the table lies a twisted piece of dark wood, one end cast in leather straps, forming a grip. There are runes carved in to the wood. You know their meaning: \"Wand of Fire\".";
const std::string crsrc::holyWaterDesc = "A bottle of holy water is lying on the floor.";
const std::string crsrc::holyWaterExDesc = "There are runes on the bottom of the bottle. They say: \"Refills automatically (neat, isn't it?)\".";
const std::string crsrc::holyWaterInitDesc = "On the desk, beside the books, stands a bottle of water. No ... holy water, taking into account the blueish glow of the substance.";
const std::string crsrc::strangerDesc = "You see a stranger leaning against the far end of the wall, examining you with cold, blue eyes.";
const std::vector<std::string> crsrc::strangerConversation = {
    "Hm. Another one. The world is going mad .... And what do you do? You wave around your sword as if you were able to do something. This is all pointless!",
    "Oh, adventurer, can it become any worse? I've lost the bottle the high priest gave me, now I'm helpless against those nastily blazing demons. By the gods, that something like this could happen to me, unthinkable. I must be getting old ...",
    "Would you please leave me alone? I'd appreciate that greatly."
};
const std::string crsrc::strangerDefVictoryMsg = "The stranger did not wish you harm. But you already started the fight. You lose ...";
const std::string crsrc::strangerDefDeathMsg = "The stranger did not wish you harm. But you already started the fight and cannot stop. You kill the stranger, watching the light fade from his piercingly blue eyes.";
const std::string crsrc::defeatStrangerLongsword = "The stranger wishes you no harm. But as you slash at him he brushes your sword away with ease. A split-second later you see his blade rush at your face with incredible speed.";
const std::string crsrc::warrioressDesc = "You see a warrioress here, seeming a bit lost but eying you with obvious distrust.";
const std::vector<std::string> crsrc::warrioressConversation = {
    "What? Do you have nothing better to do?",
    "*to herself* Damn this demon of earth. I can't get through its skin. Maybe I need something sharper as my trusty club.",
    "What? Do you have nothing better to do?"
};
const std::string crsrc::elliotDesc = "You see Elliot standing here, a man you have never met before. Or have you? How else would you know his name?";
std::vector<std::string> crsrc::elliotConversation = {
    "[NAME LINE PLACEHOLDER]",
    "Have you heard the latest gossip? We all know that the Demon King can be killed with the legendary Swords, right? Rumour has it that that you must first prove your worth to those Swords by killing four of the Demon King's minions. Only then will they obey you. But what do I know!",
    "Go on, then. Kill the demons, find the swords and kill the King. You can do it, my friend, I'm sure of it."
};
const std::string crsrc::elliotHug = "Elliot hugs you back.";
const std::string crsrc::elliotDefDeathMsg = "You land a fatal blow. But before Elliot takes his last breath, he manages to say: \"Why?\". The look in his fading eyes almost breaks your heart. This wasn't right ...";
const std::string crsrc::defeatElliotWater = "You open the bottle and throw its contents at Elliot. The bottle is refilled magically in an instant and Elliot is quite drenched now. He looks at you, quit bewildered.";
const std::string crsrc::hagDesc = "On the bed sits an old hag.";
const std::vector<std::string> crsrc::hagConversation = {
    "Oooh ... what a fine surprise ... the Chosen is finally here. You know your task already, I suppose? Quick, quick, let me tell you something then: To discover the swords you must find the three burning suns, then turn south and take the daring step. That doesn't help you? Well, this is all I know.",
    "You want to hear that again? Well, then, listen closely this time: To discover the swords you must find the three burning suns, then turn south and take the daring step. Now, now ... Go and find the Swords, Chosen. It's what you came here for, after all ...",
    "Go and find the swords, Chosen. It's what you came here for, after all ..."
};
const std::string crsrc::defeatHagWater = "You open the bottle and throw its contents at the old woman. The bottle is refilled magically in an instant and the hag is quite drenched now. She looks at you, quite bewildered.";
const std::string crsrc::scholarDesc = "You spot a scholar, frantically working through the shelves, probably searching for a particular book.";
const std::vector<std::string> crsrc::scholarConversation = {
    "Gods, how can a book be so difficult to find! Where do you hide yourself, you little rascal ...",
    "Oh, greetings. Long days and pleasant nights to thee. I didn't notice you there, say sorry. Are you in need of a book? I'm afraid the library doesn't hand them over to strangers ...",
    "Be cautious out there, okay? Those demons are vicious. They are very strong indeed and each kind can only be killed in one unique way ..."
};
const std::string crsrc::defeatScholarWater = "You open the bottle and throw its contents at the scholar. The bottle is refilled magically in an instant and the man is quite drenched now. He looks at you, quite bewildered.";
const std::string crsrc::demonKingDesc = "You see An-Harat, the Demon King, sitting on his magnificent throne and looking incredibly menacing.";
const std::vector<std::string> crsrc::demonKingConversation = {
    "Aah, greetings, Chosen. You are here at last. What took you so long? My demons certainly were no challenge for you, for you are in the possession of the legendary Swords of Dusk and Dawn, is that not so? Even as powerful a servant as Mandrak would not have been able to withstand those dreadful blades of yours, the bringers of death and destruction. Are you here to kill me, then? Do you want to take my throne? You want to take my world from me, because you think it belongs to you mortals? You want to end my eternal reign and rid the world of my kind? Come on then, try to ban me from my realm, try to destroy my immortal soul with these weapons you carry, and I'll behead you right where you stand!",
    "Come on then, try to ban me from my realm, try to destroy my immortal soul with these weapons you carry, and I'll behead you right where you stand!"
};
const std::string crsrc::demonKingHugMessage = "As you approach the Demon King, he looks at you insecurely and hesitates, but finally holds the tip of his sword to your chest so that you have to take a step back again.";
const std::string crsrc::demonKingDefVictoryMsg = "As you attack An-Harat, he brushes away your weapon without any trouble. It seems you are not yet strong enough. As you struggle to keep your balance, An-Harat comes at you, thrusts out his sword and pierces your heart.";
const std::string crsrc::victoryDemonKingSwords = "You grip the sword hilts and draw the blades. An-Harat blocks your first thrust with ease and starts a vicious counterattack, aiming for your throat. The Sword of Dusk sweeps up, deflecting An-Harat's blade. But he keeps his balance and comes at you again. He pushes you back with a series of incredibly fast attacks, and you have to step back a few paces, all while blocking his slashes with both your swords. A shallow cut appears on your arm, seeping blood. Doubt enters your mind. Can you truly defeat this beast? You feel the swords in your hands becoming warmer and strength floods back into your tired arms. You push away all thoughts and launch an attack yourself. You lunge towards your enemy, the Sword of Dawn reaching for An-Harat's chest. He blocks your thrust, but you turn around and fight on, faster and faster, until your eyes can barely see your blades anymore. You feel your foe tiring, each of his moves becoming slower and less controlled. Finally, you spot an opening in An-Harat's defense and move in for the kill. The Sword of Dawn sinks into the Demon King's chest, his sword clatters to the ground, and you look into his eyes, their fire slowly fading.";
const std::string crsrc::mandrakDesc = "You see Mandrak, the King's closest advisor and head of the Kingsguard, standing in front of the throne room, holding his lance close.";
const std::vector<std::string> crsrc::mandrakConversation = {
    "Turn back, oh powerless soul. I will let you pass, but He will kill you if you try to take his throne. Only the Swords of Dusk and Dawn can kill Him and those were lost to the world a long time ago. Long live the Demon King!",
    "Long live the Demon King!"
};
const std::string crsrc::mandrakDefVictoryMsg = "You start a fight, but Mandrak is too strong. He dodges your attacks with ease, skillfully overcomes your defenses and deals a fatal blow.";
const std::string crsrc::victoryMandrakSwords = "You start a fight. Mandrak is incredibly fast, but you are faster. Your parry every slash of his lance with ease and as soon as you spot a hole in Mandrak's defense, you strike out and deliver a fatal blow.";
const std::vector<std::string> crsrc::demonConversation = {
    "*unintellegible bestial sounds*"
};
const std::string crsrc::demonHugMessage = "You wouldn't want to hug such a hideous creature, would you?";
const std::string crsrc::fireDemonDesc = "You see a demon of fire, looking at you malevolently.";
const std::string crsrc::fireDemonDefVictoryMsg = "As you attack the demon, your weapon goes up in flames right away. As you drop your weapon to the ground, the demon points at you and a blazing ball of fire rushes at your face.";
const std::string crsrc::victoryFireDemonHolyWater = "You open the bottle and throw its content, which is refilled magically the instant the bottle is empty, killing the demon of fire.";
const std::string crsrc::defeatFireDemonWand = "You point the wand forward and as soon as you think of fire, flames spray from the tip of the wooden staff. But the demon seems to become even stronger. It points at you and a blazing ball of fire rushes at your face.";
const std::string crsrc::waterDemonDesc = "You see a demon of water, looking at you malevolently.";
const std::string crsrc::waterDemonDefVictoryMsg = "As you attack the demon, your weapon passes right through its body. Without hesitation, the demon comes at you and engulfs you with its watery body, suffocating you.";
const std::string crsrc::victoryWaterDemonWand = "You point the wand forward and as soon as you think of fire, flames spray from the tip of the wooden staff, killing the demon of water.";
const std::string crsrc::defeatWaterDemonWater = "You open the bottle and throw its content, with is refilled magically the instant the bottle is empty. But the demon seems to become even stronger. It comes at you and engulfs you with its watery body, suffocating you.";
const std::string crsrc::airDemonDesc = "You see a demon of air, looking malevolently at you.";
const std::string crsrc::airDemonDefVictoryMsg = "You can't reach the demon, as it is flying high above your head. The demon reaches out with its long claws plunges them into your chest.";
const std::string crsrc::victoryAirDemonCrossbow = "As you press the trigger, a bolt flashes from the bow, killing the demon of air.";
const std::string crsrc::earthDemonDesc = "You see a demon of earth, looking malevolently at you.";
const std::string crsrc::earthDemonDefVictoryMsg = "You cannot seem to penetrate the earth demon's thick skin. As you stand there, puzzled, the demon throws a bone-crushing punch into your face.";
const std::string crsrc::victoryEarthDemonCrossbow = "You swing your sword forward with all the power you can muster. It cuts through flesh and bone effortlessly, killing the demon of earth.";
const std::vector<std::string> crsrc::help = {
    "Some essential commands I can execute:",
    "talk -=========- talk to someone",
    "fight -========- fight someone",
    "take -=========- take something",
    "drop -=========- drop something",
    "n/e/s/w -======- go into a direction",
    "up/down -======- climb up/down"
};
const std::string crsrc::cliHelp = "the-chosen-remastered: A short ZORK-like text adventure\nUsage: the-chosen-remastered [OPTION]\n\nOptions:\n  -h, --help             Show this help message and exit\n  -v, --version          Print version info and exit\n\nNote: To learn more, type \"help\" in-game or use 'man the-chosen-remastered'";
