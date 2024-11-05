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
            const bool haveSword);
    ~Monster();
    Sword* getSword();
    void setSword(Sword* sword);
    string getStats() const;
};

#endif // MONSTER_H
