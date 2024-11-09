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

void Hero::drink(HealingPotion *healingPotion) {
    healHp(healingPotion->getHp());
    removeFromInventory(healingPotion);
}

void Hero::removeFromInventory(HealingPotion *healingPotion) {
    m_inventory->removePotion(healingPotion);
}

void Hero::addToInventory(HealingPotion* healingPotion) {
    m_inventory->addPotion(healingPotion);
}

void Hero::drink(StrengthPotion *strenghPotion) {
    updDamage(strenghPotion->getDamage());
    removeFromInventory(strenghPotion);
}

void Hero::removeFromInventory(StrengthPotion *strenghPotion) {
    m_inventory->removePotion(strenghPotion);
}

void Hero::addToInventory(StrengthPotion* strenghPotion) {
    m_inventory->addPotion(strenghPotion);
}

void Hero::drink(ResistancePotion *resistancePotion) {
    updDefence(resistancePotion->getDefence());
    removeFromInventory(resistancePotion);
}

void Hero::removeFromInventory(ResistancePotion *resistancePotion) {
    m_inventory->removePotion(resistancePotion);
}

void Hero::addToInventory(ResistancePotion *resistancePotion) {
    m_inventory->addPotion(resistancePotion);
}
