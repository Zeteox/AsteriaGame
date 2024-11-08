#include "merchant.h"
#include <QDebug>

Merchant::Merchant() {
    for (int i =0; i<30;i++) {
        m_potionStock.push_back(new Potion(getRandNumber(1,3)));
    }
    // ---Sword
    m_weaponStock.push_back(new Sword("Standard Sword", 2, 2));
    m_weaponStock.push_back(new Sword("Rare Sword", 5, 3));
    m_weaponStock.push_back(new Sword("Magical Sword", 10, 5));
    m_weaponStock.push_back(new Sword("Legendary Sword", 25, 7));
    m_weaponStock.push_back(new Sword("Mythic Sword", 75, 12));

    // ---Staff
    m_weaponStock.push_back(new Staff("Standard Staff", 2, 1));
    m_weaponStock.push_back(new Staff("Rare Staff", 5, 2));
    m_weaponStock.push_back(new Staff("Magical Staff", 10, 4));
    m_weaponStock.push_back(new Staff("Legendary Staff", 25, 6));
    m_weaponStock.push_back(new Staff("Mythic Staff", 75, 11));

    // ---Shield
    m_weaponStock.push_back(new Shield("Standard Shield", 2, 1));
    m_weaponStock.push_back(new Shield("Rare Shield", 5, 2));
    m_weaponStock.push_back(new Shield("Magical Shield", 10, 3));
    m_weaponStock.push_back(new Shield("Legendary Shield", 25, 5));
    m_weaponStock.push_back(new Shield("Mythic Shield", 75, 7));
}


vector<Weapon*> Merchant::getWeaponStock(){
    return m_weaponStock;
}

vector<Potion*> Merchant::getPotionStock(){
    return m_potionStock;
}

void Merchant::addPotion(Potion* potion){
        m_potionStock.push_back(potion);
}

void Merchant::addWeapon(Weapon* weapon){
        m_weaponStock.push_back(weapon);
}

string Merchant::removeWeapon(Weapon* weapon){
    if (m_weaponStock.size() == 0){
        return "You have no weapon to remove";
    }else{
        for (size_t i=0; i<m_weaponStock.size();i++) {
            if (m_weaponStock[i] == weapon) {
                m_weaponStock.erase(m_weaponStock.begin()+i);
                return "The weapon has been removed";
            }
        }
    }
    return "the weapon doesn't exist in the inventory";
}

string Merchant::removePotion(Potion* potion){
    if (m_potionStock.size() == 0){
        return "You have no potion to remove";
    }else{
        for (size_t i=0; i<m_potionStock.size();i++) {
            if (m_potionStock[i] == potion) {
                m_potionStock.erase(m_potionStock.begin()+i);
                return "The potion has been removed";
            }
        }
    }
    return "the potion doesn't exist in the inventory";
}
