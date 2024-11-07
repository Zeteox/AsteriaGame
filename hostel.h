#ifndef HOSTEL_H
#define HOSTEL_H

#include "livingcreature.h"

class Hostel
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
