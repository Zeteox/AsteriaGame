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

