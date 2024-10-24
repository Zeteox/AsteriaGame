#ifndef HOSTEL_H
#define HOSTEL_H

#include "building.h"
#include "livingcreature.h"

class Hostel : public Building
{
private:
    int m_price;
public:
    Hostel();
    void heal(LivingCreature *target) const;
};

#endif // HOSTEL_H
