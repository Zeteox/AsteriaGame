#include "paladin.h"

Paladin::Paladin(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class)
    : Hero(name,maxHp,golds,damage,defence,p_class){
    m_sword=new Sword("Starter Sword",0,2);
    m_shield=new Shield("Starter Shield",0,1);
}

void Paladin::setSword(Sword *newSword) {
    m_sword = newSword;
}

void Paladin::setShield(Shield *newShield) {
    m_shield = newShield;
}

Sword &Paladin::getSword() {
    return *m_sword;
}

Shield &Paladin::getShield() {
    return *m_shield;
}
