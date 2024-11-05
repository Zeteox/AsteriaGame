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
    int getPrice();
    void setPrice(int price);
    void heal(LivingCreature *target) const;
};

#endif // HOSTEL_H
