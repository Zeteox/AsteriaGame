#ifndef HEALINGPOTION_H
#define HEALINGPOTION_H

#include "potion.h"

class HealingPotion : public Potion
{
    int m_hp;
public:
    HealingPotion(int level);
    int getHp();
    void setHp(int hp);
    void createPotion(int level);
};

#endif // HEALINGPOTION_H
