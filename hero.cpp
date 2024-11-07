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

Inventory* Hero::getInventory() {
    return m_inventory;
}
