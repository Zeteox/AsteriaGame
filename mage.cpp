#include "mage.h"

Mage::Mage(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class)
    :Hero(name,maxHp,golds,damage,defence,p_class){
    //set all the attributes with a data and add a staff in the inventory
    m_staff=nullptr;
    m_dodgeChance = 20;
    m_inventory->addWeapon(new Staff("Starter Staff",0,1));
}

Mage::~Mage() {
    //delete all used memory adress
    delete m_staff;
}

int Mage::getBonuses() {
    return m_dodgeChance;
}

void Mage::setWeapon(Weapon* newWeapon) {
    if (newWeapon!= nullptr) {
        if (newWeapon->getType()=="Staff") {
            m_staff = newWeapon;
        }
    } else {
        m_staff = nullptr;
    }
    updDamage();
}

vector<Weapon*> Mage::getWeapons() {
    // return all weapons of the hero in one vector
    return vector<Weapon*>{m_staff};
}

void Mage::setDodgeChance(int newDodgeChance) {
    m_dodgeChance = newDodgeChance;
}

int Mage::getDodgeChance() {
    return m_dodgeChance;
}

string Mage::getStats() const {
    string staffName = "";
    if (m_staff == nullptr) {
        staffName = "none";
    } else {
        staffName = m_staff->getName();
    }
    return  "Name: " + m_name +
           "\nclass: " + m_class +
           "\nHp: " + to_string(m_hp) + "/" + to_string(m_maxHp) +
           "\nGold: " + to_string(m_golds) +
           "\nDamage: " + to_string(m_damage) +
           "\nDefence: " + to_string(m_defence) +
           "\nDodge chance: " + to_string(m_dodgeChance) +
           "\nStaff: " + staffName;
}

void Mage::updDamage() {
    if (m_staff != nullptr) {
        m_damage = m_baseDamage + m_staff->getDamage();
    } else {
        m_damage = m_baseDamage;
    }
}
