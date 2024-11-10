#ifndef PALADIN_H
#define PALADIN_H

#include "hero.h"

class Paladin : public Hero
{
private:
    Weapon* m_sword;
    Weapon* m_shield;
public:
    Paladin(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class);
    void setWeapon(Weapon *newWeapon);
    Weapon &getSword();
    Weapon &getShield();
    string getStats() const;
    void updDamage();
    void updDefence();
};

#endif // PALADIN_H
