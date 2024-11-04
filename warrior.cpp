#include "warrior.h"

Warrior::Warrior(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class)
    : Hero(name,maxHp,golds,damage,defence,p_class) {
    m_sword=new Sword("Starter Sword",0,2);
    m_damageBoost = 50;
}

Warrior::~Warrior() {
    delete m_sword;
}

void Warrior::setSword(Sword *newSword) {
    m_sword = newSword;
}

Sword &Warrior::getSword() {
    return *m_sword;
}

void Warrior::setDamageBoost(int newDamageBoost) {
    m_damageBoost = newDamageBoost;
}

int Warrior::getDamageBoost() const{
    return m_damageBoost;
}

string Warrior::getStats() const {
    return  "Name: " + m_name +
            "\nclass: " + m_class +
            "\nHp: " + to_string(m_hp) + "/" + to_string(m_maxHp) +
            "\nGold: " + to_string(m_golds) +
            "\nDamage: " + to_string(m_damage) +
            "\nDefence: " + to_string(m_defence) +
            "\nDamage boost: " + to_string(m_damageBoost) +
            "\nSword: " + m_sword->getName();
}

