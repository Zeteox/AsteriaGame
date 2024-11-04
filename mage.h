#ifndef MAGE_H
#define MAGE_H

#include "hero.h"
#include"staff.h"

class Mage : public Hero
{
private:
    Staff *m_staff;
    int m_dodgeChance;
public:
    Mage(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class);
    void setStaff(Staff *newStaff);
    Staff &getStaff();
    string getStats() const;
    void setDodgeChance(int newDodgeChance);
    int getDodgeChance();
    void updDamage();
};

#endif // MAGE_H
