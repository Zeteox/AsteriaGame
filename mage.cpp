#include "mage.h"

Mage::Mage(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class)
    :Hero(name,maxHp,golds,damage,defence,p_class){
    m_staff=new Staff("Starter Staff",0,2);
    m_dodgeChance = 20;
}

void Mage::setStaff(Staff *newStaff) {
    m_staff = newStaff;
}

Staff &Mage::getStaff() {
    return *m_staff;
}

void Mage::setDodgeChance(int newDodgeChance) {
    m_dodgeChance = newDodgeChance;
}

int Mage::getDodgeChance() {
    return m_dodgeChance;
}

string Mage::getStats() const {
    return  "Name: " + m_name +
           "\nclass: " + m_class +
           "\nHp: " + to_string(m_hp) + "/" + to_string(m_maxHp) +
           "\nGold: " + to_string(m_golds) +
           "\nDamage: " + to_string(m_damage) +
           "\nDefence: " + to_string(m_defence) +
           "\nDodge chance: " + to_string(m_dodgeChance) +
            "\nStaff: " + m_staff->getName();
}

void Mage::updDamage() {
    if (m_staff != nullptr) {
        m_damage = m_baseDamage + m_staff->getDamage();
    } else {
        m_damage = m_baseDamage;
    }
}
