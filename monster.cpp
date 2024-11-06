
#include "monster.h"

Monster::Monster(const string name, const int maxHp, const int golds, const int damage, const int defence,
                 const bool haveSword, const bool haveShield, const bool haveStaff)
    : LivingCreature( name, maxHp, golds, damage, defence){
    if(haveSword == true){
        m_sword = new Sword("Standar Sword", 1, 2);
    }else{
        m_sword = nullptr;
    }
    if(haveShield == true){
        m_shield = new Shield("Starter Shield",0,1);
    }else{
        m_shield = nullptr;
    }
    if(haveStaff == true){
        m_staff = new Staff("Standar Staff", 1, 2);
    }else{
        m_staff = nullptr;
    }
}

Sword* Monster::getSword(){
    return m_sword;
}

void Monster::setSword(Sword* sword){
    m_sword = sword;
}

Shield* Monster::getShield(){
    return m_shield;
}

void Monster::setShield(Shield* shield){
    m_shield = shield;
}

Staff* Monster::getStaff(){
    return m_staff;
}

void Monster::setStaff(Staff* staff){
    m_staff = staff;
}

string Monster::getStats() const {
    return "Name: " + m_name +
           "\nHp: " + to_string(m_hp) + "/" + to_string(m_maxHp) +
           "\nGold: " + to_string(m_golds) +
           "\nDamage: " + to_string(m_damage) +
           "\nDefence: " + to_string(m_defence) +
           "\nSword: " + m_sword->getName();
           "\nShield: " + m_shield->getName();
           "\nStaff: " + m_staff->getName();
}

void Monster::updDamage() {
    if (m_sword != nullptr) {
        m_damage = m_baseDamage + m_sword->getDamage();
    }else if(m_staff != nullptr){
        m_damage = m_baseDamage + m_staff->getDamage();
    }else{
        m_damage = m_baseDamage;
    }
}

void Monster::updDefence() {
    if (m_shield != nullptr) {
        m_defence = m_baseDefence + m_shield->getDefence();
    } else {
        m_defence = m_baseDefence;
    }
}
