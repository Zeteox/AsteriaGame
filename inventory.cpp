#include "inventory.h"

Inventory::Inventory() {
    m_space = 10;
}
size_t Inventory::getSpace(){
    return m_space;
}

string Inventory::addSpace(){
    m_space += 10;
    return "You have more space";
}

vector<Potion*> Inventory::showPotions(){
    return m_potions;
}

string Inventory::addPotion(Potion* potion){
    if (m_potions.size() + m_weapons.size() < m_space) {
        m_potions.push_back(potion);
        return "The potion has been added";
    }else{
        return "The Inventory is full";
    }
}

string Inventory::removePotion(Potion* potion){
    if (m_potions.size() == 0){
        return "You have no potion to remove";
    }else{
        for (size_t i=0; i<m_potions.size();i++) {
            if (m_potions[i] == potion) {
                m_potions.erase(m_potions.begin()+i);
                return "The potion has been removed";
            }
        }
    }
    return "the potion doesn't exist in the inventory";
}

vector<Weapon*> Inventory::showWeapons(){
    return m_weapons;
}

string Inventory::addWeapon(Weapon* weapon){
    if (m_potions.size() + m_weapons.size() < m_space) {
        m_weapons.push_back(weapon);
        return "The weapon has been added";
    }else{
        return "The Inventory is full";
    }
}

string Inventory::removeWeapon(Weapon* weapon){
    if (m_weapons.size() == 0){
        return "You have no weapon to remove";
    }else{
        for (size_t i=0; i<m_weapons.size();i++) {
            if (m_weapons[i] == weapon) {
                m_weapons.erase(m_weapons.begin()+i);
                return "The weapon has been removed";
            }
        }
    }
    return "the weapon doesn't exist in the inventory";
}
