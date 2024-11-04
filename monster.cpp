
#include "monster.h"
#include "sword.h"

Monster::Monster(const string name, const int maxHp, const int golds, const int damage, const int defence, const bool haveSword,
                 const string swordName, const int swordPrice, int swordDamage) : LivingCreature( name, maxHp, golds, damage, defence){
    if(haveSword == true){
        m_sword = new Sword(swordName,swordPrice,swordDamage);
    }
}

Sword* Monster::getSword(){
    return m_sword;
}

void Monster::setSword(Sword* sword){
    m_sword = sword;
}
