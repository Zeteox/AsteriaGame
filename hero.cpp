#include "hero.h"
#include <QDebug>

Hero::Hero(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class)
    : LivingCreature(name, maxHp, golds, damage, defence) {
    m_class = p_class;
}

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

void Hero::removeFromInventory(Potion *potion) {
    m_inventory->removePotion(potion);
}

void Hero::addToInventory(Potion* potion) {
    m_inventory->addPotion(potion);
}

Inventory* Hero::getInventory() {
    return m_inventory;
}
