#include "merchant.h"

Merchant::Merchant() : Building("Merchant"){
}


vector<Sword*> Merchant::getSwordStock(){
    return m_swordStock;
}
vector<Shield*> Merchant::getShieldStock(){
    return m_shieldStock;
}
vector<Staff*> Merchant::getStaffStock(){
    return m_staffStock;
}
vector<Potion*> Merchant::getPotionStock(){
    return m_potionStock;
}

string Merchant::removeSword(Sword* sword){
    if (m_swordStock.size() == 0){
        return "You have no sword to remove";
    }else{
        for (size_t i=0; i<m_swordStock.size();i++) {
            if (m_swordStock[i] == sword) {
                m_swordStock.erase(next(m_swordStock.begin()+i));
                return "The sword has been removed";
            }
        }
    }
    return "the sword doesn't exist in the inventory";
}

string Merchant::removeShield(Shield* shield){
    if (m_shieldStock.size() == 0){
        return "You have no shield to remove";
    }else{
        for (size_t i=0; i<m_shieldStock.size();i++) {
            if (m_shieldStock[i] == shield) {
                m_shieldStock.erase(m_shieldStock.begin()+i);
                return "The shield has been removed";
            }
        }
    }
    return "the shield doesn't exist in the inventory";
}

string Merchant::removeStaff(Staff* staff){
    if (m_staffStock.size() == 0){
        return "You have no staff to remove";
    }else{
        for (size_t i=0; i<m_staffStock.size();i++) {
            if (m_staffStock[i] == staff) {
                m_staffStock.erase(m_staffStock.begin()+i);
                return "The staff has been removed";
            }
        }
    }
    return "the staff doesn't exist in the inventory";
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
