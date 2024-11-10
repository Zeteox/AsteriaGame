#include "hostel.h"
#include "randomNumber.h"

Hostel::Hostel() {
    //The constructor sets the attribute m_price to a random number between 5 and 15.
    m_price = getRandNumber(5, 15);
}

int Hostel::getPrice(){
    return m_price;
}

void Hostel::setPrice(int price){
    m_price = price;
}
void Hostel::heal(LivingCreature *target) const{
    //The heal method maximizes the player's Hp.
    target->healHp(target->getMaxHp());
}
