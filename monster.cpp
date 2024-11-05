
#include "monster.h"
#include "sword.h"

Monster::Monster(const string name, const int maxHp, const int golds, const int damage, const int defence, const bool haveSword)
    : LivingCreature( name, maxHp, golds, damage, defence){
    if(haveSword == true){
        m_sword = new Sword("Standar Sword", 1, 2);
    }else{
        m_sword = nullptr;
    }
}

Sword* Monster::getSword(){
    return m_sword;
}

void Monster::setSword(Sword* sword){
    m_sword = sword;
}

string Monster::getStats() const {
    return  "Name: " + m_name +
           "\nHp: " + to_string(m_hp) + "/" + to_string(m_maxHp) +
           "\nGold: " + to_string(m_golds) +
           "\nDamage: " + to_string(m_damage) +
           "\nDefence: " + to_string(m_defence) +
           "\nSword: " + m_sword->getName();
}
