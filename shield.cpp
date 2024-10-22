#include "shield.h"
#include <QDebug>

Shield::Shield(const string& name, const int price, int defence)
    : Weapon(name, price) {
    m_defence=defence;
}

void Shield::setDefence(int newDefence) {
    m_defence = newDefence;
}

int Shield::getDefence() const {
    return m_defence;
}

void Shield::showStats() const {
    qDebug()<< "Name:"<< m_name<<"\nPrice:"<< m_price <<"\nDefence:"<<m_defence;
}
