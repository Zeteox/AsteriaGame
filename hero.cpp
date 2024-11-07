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

void Hero::drink(Potion *potion) {
    healHp(potion->getHp());
    removeFromInventory(potion);
}

string Hero::removeFromInventory(Potion *potion) {
    return m_inventory->removePotion(potion);
}

string Hero::addToInventory(Potion* potion) {
    return m_inventory->addPotion(potion);
}

string Hero::addToInventory(Weapon* weapon) {
    return m_inventory->addWeapon(weapon);
}

Inventory* Hero::getInventory() {
    return m_inventory;
}

void Hero::trade(Merchant* merchant, string objectType, int index) {
    if (objectType == "Potion") {
        addToInventory(merchant->getPotionStock()[index]);
        setGolds(m_golds-merchant->getPotionStock()[index]->getPrice());
        merchant->getPotionStock().erase(merchant->getPotionStock().begin() + index);
    } else if (objectType == "Weapon") {
        addToInventory(merchant->getWeaponStock()[index]);
        setGolds(m_golds-merchant->getWeaponStock()[index]->getPrice());
        merchant->getWeaponStock().erase(merchant->getWeaponStock().begin() + index);
    }
}
