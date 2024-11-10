#include "weapon.h"

Weapon::Weapon(const string &name, const int price) {
    m_name = name;
    m_type = "";
    m_price = price;
    for (int i = 1; i<=6;i++) {
        m_swordIconsPath.push_back(":/Images/Images/Button/sword/sword"+to_string(i)+".png");
    }
    for (int i = 1; i<=6;i++) {
        m_staffIconsPath.push_back(":/Images/Images/Button/staff/staff"+to_string(i)+".png");
    }
    for (int i = 1; i<=5;i++) {
        m_shieldIconsPath.push_back(":/Images/Images/Button/shield/shield"+to_string(i)+".png");
    }
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

vector<string> Weapon::getSwordIconsPath() {
    return m_swordIconsPath;
}

vector<string> Weapon::getStaffIconsPath() {
    return m_staffIconsPath;
}

vector<string> Weapon::getShieldIconsPath() {
    return m_shieldIconsPath;
}
