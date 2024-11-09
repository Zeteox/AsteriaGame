#include "healingpotion.h"

HealingPotion::HealingPotion(int level) : Potion(){
    createPotion(level);
}

int HealingPotion::getHp(){
    return m_hp;
}
void HealingPotion::setHp(int hp) {
    m_hp = hp;
}
void HealingPotion::createPotion(int level){
    switch(level){
    case 1 :
        m_name = "Small Potion", m_hp = 3, m_price = 5;
        break;
    case 2 :
        m_name = "Medium Potion", m_hp = 8, m_price = 10;
        break;
    case 3 :
        m_name = "Big Potion", m_hp = 18, m_price = 20;
        break;
    case 4 :
        m_name = "Divine Potion", m_hp = 10000, m_price = -1;
        break;
    case 5 :
        m_name = "Divine Potiom", m_hp = 10000, m_price = -1;
        break;
    }
}
