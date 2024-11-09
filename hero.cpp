#include "hero.h"
#include <QDebug>

Hero::Hero(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class)
    : LivingCreature(name, maxHp, golds, damage, defence) {
    m_class = p_class;
    m_inventory = new Inventory;
}

Hero::~Hero() {}

string& Hero::getClass() {
    return m_class;
}

string Hero::talk() const {
    return "je suis le hero " + m_name;
}

int Hero::getBonuses(){
    return 0;
}

void Hero::drink(Potion *potion) {
    if (m_hp<m_maxHp) {
        healHp(potion->getHp());
        removeFromInventory(potion);
    }
}

string Hero::removeFromInventory(Potion *potion) {
    return m_inventory->removePotion(potion);
}

string Hero::removeFromInventory(Weapon *weapon) {
    return m_inventory->removeWeapon(weapon);
}


string Hero::addToInventory(Potion *potion) {
    return m_inventory->addPotion(potion);
}

string Hero::addToInventory(Weapon *weapon) {
    return m_inventory->addWeapon(weapon);
}

Inventory* Hero::getInventory() {
    return m_inventory;
}

void Hero::trade(Merchant* merchant, Potion *potion) {
    addToInventory(potion);
    setGolds(getGolds()-potion->getPrice());
    merchant->removePotion(potion);
}

void Hero::trade(Merchant* merchant, Weapon *weapon) {
    addToInventory(weapon);
    setGolds(getGolds()-weapon->getPrice());
    merchant->removeWeapon(weapon);
}

void Hero::sell(Merchant* merchant, Potion *potion) {
    merchant->addPotion(potion);
    setGolds(getGolds()+potion->getPrice());
    removeFromInventory(potion);
}

void Hero::sell(Merchant* merchant, Weapon *weapon) {
    merchant->addWeapon(weapon);
    setGolds(getGolds()+weapon->getPrice());
    removeFromInventory(weapon);
}
