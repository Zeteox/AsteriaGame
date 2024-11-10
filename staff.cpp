#include "staff.h"
#include <QDebug>

Staff::Staff(const string &name, const int price, int damage)
    : Weapon(name, price) {
    //give a data to all attributes
    m_type="Staff";
    m_damage=damage;
}

void Staff::setDamage(int newDamage) {
    m_damage = newDamage;
}

int Staff::getDamage() const {
    return m_damage;
}

string Staff::getStats() const {
    //return weapon stats
    return "Name: " + m_name +
           "\nPrice: " + to_string(m_price) +
           "\nDamage: "+ to_string(m_damage);
}
