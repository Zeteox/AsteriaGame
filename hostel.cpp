#include "hostel.h"
#include "randomNumber.h"

Hostel::Hostel() : Building("Hostel") {
    m_price = getRandNumber(5, 15);
}

int Hostel::getPrice(){
    return m_price;
}

void Hostel::setPrice(int price){
    m_price = price;
}
void Hostel::heal(LivingCreature *target) const{
    target->healHp(target->getMaxHp());
}
