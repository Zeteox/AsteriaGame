#include "resistancepotion.h"

ResistancePotion::ResistancePotion(int level) : Potion() {
    createPotion(level);
}

int ResistancePotion::getDefence(){
    return m_defence;
}
void ResistancePotion::setDefence(int defence) {
    m_defence = defence;
}
void ResistancePotion::createPotion(int level){
    switch(level){
    case 1 :
        m_name = "Small Potion", m_defence = 3, m_price = 5;
        break;
    case 2 :
        m_name = "Medium Potion", m_defence = 8, m_price = 10;
        break;
    case 3 :
        m_name = "Big Potion", m_defence = 18, m_price = 20;
        break;
    case 4 :
        m_name = "Divine Potion", m_defence = 10000, m_price = -1;
        break;
    case 5 :
        m_name = "Divine Potiom", m_defence = 10000, m_price = -1;
        break;
    }
}
