#include "merchant.h"
#include <QDebug>

Merchant::Merchant() {
    //The constructor fills the m_potionStock attribute of 30 potions
    //of levels 1 to 3 and m_weaponStock of all available weapons.
    for (int i =0; i<30;i++) {
        m_potionStock.push_back(new Potion(getRandNumber(1,3)));
    }
    // ---Sword
    m_weaponStock.push_back(new Sword("Standard Sword", 4, 2));
    m_weaponStock.push_back(new Sword("Rare Sword", 10, 3));
    m_weaponStock.push_back(new Sword("Magical Sword", 20, 5));
    m_weaponStock.push_back(new Sword("Legendary Sword", 50, 7));
    m_weaponStock.push_back(new Sword("Mythic Sword", 140, 12));

    // ---Staff
    m_weaponStock.push_back(new Staff("Standard Staff", 4, 1));
    m_weaponStock.push_back(new Staff("Rare Staff", 10, 2));
    m_weaponStock.push_back(new Staff("Magical Staff", 20, 4));
    m_weaponStock.push_back(new Staff("Legendary Staff", 50, 6));
    m_weaponStock.push_back(new Staff("Mythic Staff", 140, 11));

    // ---Shield
    m_weaponStock.push_back(new Shield("Standard Shield", 4, 1));
    m_weaponStock.push_back(new Shield("Rare Shield", 10, 2));
    m_weaponStock.push_back(new Shield("Magical Shield", 20, 3));
    m_weaponStock.push_back(new Shield("Legendary Shield", 50, 5));
    m_weaponStock.push_back(new Shield("Mythic Shield", 140, 7));
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
    //The removeWeapon method removes from merchant
    //the weapon entered as an argument.
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
    //The removePotion method removes from merchant
    //the potion entered as an argument.
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
