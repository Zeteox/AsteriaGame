#include "strengthpotion.h"

StrengthPotion::StrengthPotion(int level) : Potion(){
    createPotion(level);
}
int StrengthPotion::getDamage(){
    return m_damage;
}
void StrengthPotion::setDamage(int damage) {
    m_damage = damage;
}
void StrengthPotion::createPotion(int level){
    switch(level){
    case 1 :
        m_name = "Small Potion", m_damage = 3, m_price = 5;
        break;
    case 2 :
        m_name = "Medium Potion", m_damage = 8, m_price = 10;
        break;
    case 3 :
        m_name = "Big Potion", m_damage = 18, m_price = 20;
        break;
    case 4 :
        m_name = "Divine Potion", m_damage = 10000, m_price = -1;
        break;
    case 5 :
        m_name = "Divine Potiom", m_damage = 10000, m_price = -1;
        break;
    }
}
