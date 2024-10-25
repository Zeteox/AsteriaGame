#ifndef MONSTER_H
#define MONSTER_H

#include "livingcreature.h"
#include "sword.h"

class Monster : public LivingCreature
{
private:
    Sword *m_sword;
public:
    Monster();
    Sword* getSword();
    void setSword(Sword* sword);
};

#endif // MONSTER_H
