#include "staff.h"
#include <QDebug>

Staff::Staff(const string& name, const int price, int damage)
    : Weapon(name, price) {
    m_damage=damage;
}

void Staff::setDamage(int newDamage) {
    m_damage = newDamage;
}

int Staff::getDamage() const {
    return m_damage;
}

string Staff::getStats() const {
    return "Name: " + m_name +
           "\nPrice: " + to_string(m_price) +
           "\nDamage: "+ to_string(m_damage);
}
