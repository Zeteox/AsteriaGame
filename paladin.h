#ifndef PALADIN_H
#define PALADIN_H

#include "hero.h"
#include "sword.h"
#include "shield.h"

class Paladin : public Hero
{
private:
    Sword* m_sword;
    Shield* m_shield;
public:
    Paladin(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class);
    void setSword(Sword *newSword);
    Sword &getSword();
    void setShield(Shield *newShield);
    Shield &getShield();
};

#endif // PALADIN_H
