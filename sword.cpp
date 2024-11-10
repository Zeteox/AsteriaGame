#include "sword.h"
#include <QDebug>

Sword::Sword(const string &name, const int price, int damage)
    : Weapon(name, price) {
    //give a data to all attributes
    m_type = "Sword";
    m_damage=damage;
}

Sword::~Sword() {

}

void Sword::setDamage(int newDamage) {
    m_damage = newDamage;
}

int Sword::getDamage() const {
    return m_damage;
}

string Sword::getStats() const {
    //return weapon stats
    return "Name: " + m_name +
           "\nPrice: " + to_string(m_price) +
           "\nDamage: "+ to_string(m_damage);
}
