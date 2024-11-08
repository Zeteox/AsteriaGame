#include "paladin.h"

Paladin::Paladin(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class)
    : Hero(name,maxHp,golds,damage,defence,p_class){
    m_sword=nullptr;
    m_shield=nullptr;
    m_inventory->addWeapon(new Sword("Starter Sword",0,1));
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

string Paladin::getStats() const {
    string swordName = "";
    if (m_sword == nullptr) {
        swordName = "none";
    } else {
        swordName = m_sword->getName();
    }
    string shieldName = "";
    if (m_shield == nullptr) {
        shieldName = "none";
    } else {
        shieldName = m_shield->getName();
    }
    return  "Name: " + m_name +
            "\nclass: " + m_class +
            "\nHp: " + to_string(m_hp) + "/" + to_string(m_maxHp) +
            "\nGold: " + to_string(m_golds) +
            "\nDamage: " + to_string(m_damage) +
            "\nDefence: " + to_string(m_defence) +
            "\nSword: " + swordName +
            "\nShield: " + shieldName;
}

void Paladin::updDamage() {
    if (m_sword != nullptr) {
        m_damage = m_baseDamage + m_sword->getDamage();
    } else {
        m_damage = m_baseDamage;
    }
}

void Paladin::updDefence() {
    if (m_shield != nullptr) {
        m_defence = m_baseDefence + m_shield->getDefence();
    } else {
        m_defence = m_baseDefence;
    }
}
