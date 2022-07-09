#include "DragonSlayer.h"
#include "Dragon.h"
#include "Utility.h"
#include "AttackItem.h"

//DragonSlayer::DragonSlayer
DragonSlayer::DragonSlayer(std::string name_, int hp, int armor) : Character(hp, armor, 4), name(name_)
{
    helpfulItems = makeHelpfulItems(1);
    defensiveItems = makeDefensiveItems(9);
}

//DragonSlayer::getName
const std::string& DragonSlayer::getName()
{
    return name;
}

void DragonSlayer::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;
    if( auto* dragon = dynamic_cast<Dragon*>(&other) )
    {
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        //so they should USE their attack item before attacking the dragon...
        //note: they should only use the item if the dragon's hitpoints are > 0...
        //note: items are single-use only, so you need to reset it after use.
        //look in the Character class for how the other item types are reset after use.
        if( attackItem != nullptr && dragon->getHP() > 0 )
        {
            attackItem->use(this);
            attackItem.reset();
        }
        
        while( dragon->getHP() > 0 )
        {
            dragon->takeDamage(attackDamage);
        }
    }
        
    Character::attack(other);
        
}

//DragonSlayer::getStats
std::string DragonSlayer::getStats()
{
    return getCharacterStats(this);
}

