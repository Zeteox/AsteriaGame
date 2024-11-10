#include "hero.h"
#include <QDebug>

Hero::Hero(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class)
    : LivingCreature(name, maxHp, golds, damage, defence) {
    //set a class to the hero in function of the given arg,
    //and create a new inventory in the relative attribute
    m_class = p_class;
    m_inventory = new Inventory;
}

Hero::~Hero() {
    //delete all used memory adress
    delete m_inventory;
}

string& Hero::getClass() {
    return m_class;
}

void Hero::setWeapon(Weapon*) {}

vector<Weapon*> Hero::getWeapons() {
    //return a empty vector because Hero class doesnt have weapons
    return vector<Weapon*>{};
}

int Hero::getBonuses(){
    return 0;
}

void Hero::drink(Potion *potion) {
    //heal hp in function of the given potion and delete it
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
    //trade a given potion with a given merchant
    addToInventory(potion);
    setGolds(getGolds()-potion->getPrice());
    merchant->removePotion(potion);
}

void Hero::trade(Merchant* merchant, Weapon *weapon) {
    //trade a given weapon with a given merchant
    addToInventory(weapon);
    setGolds(getGolds()-weapon->getPrice());
    merchant->removeWeapon(weapon);
}

void Hero::sell(Merchant* merchant, Potion *potion) {
    //sell a given potion to a given merchant
    merchant->addPotion(potion);
    setGolds(getGolds()+potion->getPrice());
    removeFromInventory(potion);
}

void Hero::sell(Merchant* merchant, Weapon *weapon) {
    //sell a given weapon to a given merchant
    merchant->addWeapon(weapon);
    setGolds(getGolds()+weapon->getPrice());
    removeFromInventory(weapon);
}
