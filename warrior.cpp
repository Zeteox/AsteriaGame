#include "warrior.h"

Warrior::Warrior(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class)
    : Hero(name,maxHp,golds,damage,defence,p_class) {
    //set all the attributes with a data and add a sword in the inventory
    m_sword=nullptr;
    m_damageBoost = 50;
    m_inventory->addWeapon(new Sword("Starter Sword",0,1));
}

Warrior::~Warrior() {
    //delete all used memory adress
    delete m_sword;
}

int Warrior::getBonuses(){
    return m_damageBoost;
}

void Warrior::setWeapon(Weapon* newWeapon) {
    //set m_sword to the new weapon if it's not null and a Sword
    if (newWeapon != nullptr) {
        if (newWeapon->getType()=="Sword") {
            m_sword = newWeapon;
        }
    } else {
        m_sword = nullptr;
    }
    updDamage();
}

vector<Weapon*> Warrior::getWeapons() {
    //return all weapons of the hero in one vector
    return vector<Weapon*>{m_sword};
}

void Warrior::setDamageBoost(int newDamageBoost) {
    m_damageBoost = newDamageBoost;
}

int Warrior::getDamageBoost() const{
    return m_damageBoost;
}

string Warrior::getStats() const {
    //return the stats of the hero
    string swordName = "";
    if (m_sword == nullptr) {
        swordName = "none";
    } else {
        swordName = m_sword->getName();
    }
    return  "Name: " + m_name +
            "\nclass: " + m_class +
            "\nHp: " + to_string(m_hp) + "/" + to_string(m_maxHp) +
            "\nGold: " + to_string(m_golds) +
            "\nDamage: " + to_string(m_damage) +
            "\nDefence: " + to_string(m_defence) +
            "\nDamage boost: " + to_string(m_damageBoost) +
            "\nSword: " + swordName;
}

void Warrior::updDamage() {
    //update the m_damage variables in function of the weapon
    if (m_sword != nullptr) {
        m_damage = m_baseDamage + m_sword->getDamage();
    } else {
        m_damage = m_baseDamage;
    }
}
