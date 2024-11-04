#include "inventory.h"

Inventory::Inventory() {
    m_space = 10;
}
size_t Inventory::getSpace(){
    return m_space;
}

vector<Potion*> Inventory::showPotions(){
    return m_potions;
}

string Inventory::addPotion(Potion* potion){
    if (m_potions.size()<m_space) {
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
            if (m_potions[i]->getName()==potion->getName()) {
                m_potions.erase(next(m_potions.begin()+i));
                return "The potion has been removed";
            }
        }
    }
    return "the potion doesn't exist in the inventory";
}
string Inventory::addSpace(){
    m_space += 10;
    return "You have more space";
}
