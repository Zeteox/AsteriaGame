#include "shield.h"
#include <QDebug>

Shield::Shield(const string &name, const int price, int defence)
    : Weapon(name, price) {
    m_type="Shield";
    m_defence=defence;
}

void Shield::setDefence(int newDefence) {
    m_defence = newDefence;
}

int Shield::getDefence() const {
    return m_defence;
}

string Shield::getStats() const {
    return "Name: " + m_name +
           "\nPrice: " + to_string(m_price) +
           "\nDefence: "+ to_string(m_defence);
}
