#include "potion.h"

Potion::Potion(){

}
string& Potion::getName() {
    return m_name;
}
void Potion::setName(string name) {
    m_name = name;
}
void Potion::setPrice(int price) {
    m_price = price;
}
int Potion::getPrice() {
    return m_price;
}
void Potion::createPotion(int level){
    switch(level){
    case 1 :
        m_name = "Small Potion", m_price = 5;
        break;
    case 2 :
        m_name = "Medium Potion", m_price = 10;
        break;
    case 3 :
        m_name = "Big Potion", m_price = 20;
        break;
    case 4 :
        m_name = "Divine Potion", m_price = -1;
        break;
    case 5 :
        m_name = "Divine Potiom", m_price = -1;
        break;
    }
}
