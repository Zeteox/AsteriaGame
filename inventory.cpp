#include "inventory.h"

Inventory::Inventory() {
    //The constructor sets the m_space attribute to 10.
    m_space = 10;
}
Inventory::~Inventory(){
    // The destructor delete the inventory.
    for(size_t x = 0; x< m_potions.size(); x++){
        delete m_potions[x];
    }
    for(size_t x = 0; x< m_weapons.size(); x++){
        delete m_weapons[x];
    }
}
size_t Inventory::getSpace(){
    return m_space;
}

string Inventory::addSpace(){
    m_space += 10;
    return "You have more space";
}

vector<Potion*> Inventory::getPotions(){
    return m_potions;
}

string Inventory::addPotion(Potion* potion){
    //The addPotion method checks if the inventory is full
    //and adds a potion if possible.
    if (m_potions.size() + m_weapons.size() < m_space) {
        m_potions.push_back(potion);
        return "The potion has been added";
    }else{
        return "The Inventory is full";
    }
}

string Inventory::removePotion(Potion* potion){
    //The removePotion method removes from inventory
    //the potion entered as an argument.
    if (m_potions.size() == 0){
        return "You have no potion to remove";
    }else{
        for (size_t i=0; i<m_potions.size();i++) {
            if (m_potions[i] == potion) {
                delete potion;
                m_potions.erase(m_potions.begin()+i);
                return "The potion has been removed";
            }
        }
    }
    return "the potion doesn't exist in the inventory";
}

vector<Weapon*> Inventory::getWeapons(){
    return m_weapons;
}

string Inventory::addWeapon(Weapon* weapon){
    //The addWeapon method checks if the inventory is
    //full and adds a weapon if possible.
    if (m_potions.size() + m_weapons.size() < m_space) {
        m_weapons.push_back(weapon);
        return "The weapon has been added";
    }else{
        return "The Inventory is full";
    }
}

string Inventory::removeWeapon(Weapon* weapon){
    //The removePotion method removes from inventory
    //the weapon entered as an argument.
    if (m_weapons.size() == 0){
        return "You have no weapon to remove";
    }else{
        for (size_t i=0; i<m_weapons.size();i++) {
            if (m_weapons[i] == weapon) {
                delete weapon;
                m_weapons.erase(m_weapons.begin()+i);
                return "The weapon has been removed";
            }
        }
    }
    return "the weapon doesn't exist in the inventory";
}
