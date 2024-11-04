#include "sword.h"
#include <QDebug>

Sword::Sword(const string& name, const int price, int damage)
    : Weapon(name, price) {
    m_damage=damage;
}

void Sword::setDamage(int newDamage) {
    m_damage = newDamage;
}

int Sword::getDamage() const {
    return m_damage;
}

string Sword::getStats() const {
    return "Name: " + m_name +
           "\nPrice: " + to_string(m_price) +
           "\nDamage: "+ to_string(m_damage);
}
