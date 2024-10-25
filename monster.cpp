
#include "monster.h"
#include "sword.h"

Monster::Monster() : LivingCreature("Monster", 25, 3, 5, 5){
    m_sword = new Sword("StandarSword",5,15);
}

Sword* Monster::getSword(){
    return m_sword;
}

void Monster::setSword(Sword* sword){
    m_sword = sword;
}
