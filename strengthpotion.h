#ifndef STRENGTHPOTION_H
#define STRENGTHPOTION_H

#include "potion.h"

class StrengthPotion : public Potion
{
    int m_damage;
public:
    StrengthPotion(int level);
    int getDamage();
    void setDamage(int damage);
    void createPotion(int level);
};

#endif // STRENGTHPOTION_H
