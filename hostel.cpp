#include "hostel.h"

Hostel::Hostel() : Building("Hostel") {
    m_price = ;
}

void Hostel::heal(LivingCreature *target) const{
    target->healHp(target->getMaxHp());
}
