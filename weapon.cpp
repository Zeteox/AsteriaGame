#include "weapon.h"

Weapon::Weapon(const string &name, const int price) {
    //give a data to all attributes
    m_name = name;
    m_type = "";
    m_price = price;
}

Weapon::~Weapon() {}

string &Weapon::getType() {
    return m_type;
}

int Weapon::getDamage() const {
    return 0;
}

int Weapon::getDefence() const {
    return 0;
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
