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
    ~Paladin();
    void setWeapon(Weapon *newWeapon);
    vector<Weapon*> getWeapons();
    string getStats() const;
    void updDamage();
    void updDefence();
};

#endif // PALADIN_H
