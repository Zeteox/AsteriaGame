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
