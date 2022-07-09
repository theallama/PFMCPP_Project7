#include "Dwarf.h"
#include "Utility.h"

//Dwarf::Dwarf
Dwarf::Dwarf (std::string name_, int hp, int armor) : Character(hp, armor, 4), name(name_)
{
     defensiveItems = makeDefensiveItems(4);
    helpfulItems = makeHelpfulItems(1);
}

//Dwarf::getName
const std::string& Dwarf::getName()
{
    return name;
}

//Dwarf::getStats
std::string Dwarf::getStats()
{
    return getCharacterStats(this);
}

