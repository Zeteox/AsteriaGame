#include "sword.h"
#include <QDebug>

Sword::Sword(const string &name, const int price, int damage)
    : Weapon(name, price) {
    m_damage=damage;
}

void Sword::setDamage(int newDamage) {
    m_damage = newDamage;
}

int Sword::getDamage() const {
    return m_damage;
}

void Sword::showStats() const {
    qDebug()<< "Name:"<< m_name<<"\nPrice:"<< m_price <<"\nDamage:"<<m_damage;
}
