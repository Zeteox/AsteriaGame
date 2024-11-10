#ifndef WARRIOR_H
#define WARRIOR_H

#include <hero.h>
#include "sword.h"

class Warrior : public Hero
{
private:
    Weapon* m_sword;
    int m_damageBoost;
public:
    Warrior(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class);
    virtual ~Warrior();
    void setWeapon(Weapon* newWeapon);
    vector<Weapon*> getWeapons();
    void setDamageBoost(int newDamageBoost);
    string getStats() const;
    int getDamageBoost()const;
    void updDamage();
    int getBonuses();
};

#endif // WARRIOR_H
