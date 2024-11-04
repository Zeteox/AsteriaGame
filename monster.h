#ifndef MONSTER_H
#define MONSTER_H

#include "livingcreature.h"
#include "sword.h"

class Monster : public LivingCreature
{
private:
    Sword *m_sword;
public:
    Monster(const string name, const int maxHp, const int golds, const int damage, const int defence,
            const bool haveSword, const string swordName, const int swordPrice, int swordDamage );
    Sword* getSword();
    void setSword(Sword* sword);
};

#endif // MONSTER_H
