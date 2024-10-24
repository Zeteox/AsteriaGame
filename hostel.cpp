#include "hostel.h"

Hostel::Hostel() : Building("Hostel") {
    m_price = 1;
}

void Hostel::heal(LivingCreature *target) const{
    target->healHp(target->getMaxHp());
}
