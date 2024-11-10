#ifndef MAGE_H
#define MAGE_H

#include "hero.h"
#include"staff.h"

class Mage : public Hero
{
private:
    Weapon *m_staff;
    int m_dodgeChance;
public:
    Mage(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class);
    ~Mage();
    void setWeapon(Weapon *newWeapon);
    vector<Weapon*> getWeapons();
    string getStats() const;
    void setDodgeChance(int newDodgeChance);
    int getDodgeChance();
    void updDamage();
    int getBonuses();
};

#endif // MAGE_H
