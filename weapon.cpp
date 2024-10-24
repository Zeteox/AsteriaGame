#include "weapon.h"

Weapon::Weapon(const string &name, const int price) {
    m_name = name;
    m_price = price;
}

string &Weapon::getName() {
    return m_name;
}

void Weapon::setPrice(int newPrice) {
    if (newPrice >=0) {
        m_price = newPrice;
    }
}

int Weapon::getPrice() const {
    return m_price;
}
