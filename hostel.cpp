#include "hostel.h"
#include "randomNumber.h"

Hostel::Hostel() : Building("Hostel") {
    m_price = getRandNumber(5, 15);
}

void Hostel::heal(LivingCreature *target) const{
    target->healHp(target->getMaxHp());
}
