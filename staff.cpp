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

void Staff::showStats() const {
    qDebug()<< "Name:"<< m_name<<"\nPrice:"<< m_price <<"\nDamage:"<<m_damage;
}
