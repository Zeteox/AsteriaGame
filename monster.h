#ifndef MONSTER_H
#define MONSTER_H

#include "livingcreature.h"
#include "shield.h"
#include "staff.h"
#include "sword.h"

class Monster : public LivingCreature
{
private:
    Sword *m_sword;
    Shield* m_shield;
    Staff* m_staff;
public:
    Monster(const string name, const int maxHp, const int golds, const int damage, const int defence,
            const bool haveSword, const bool haveShield, const bool haveStaff);
    ~Monster();
    Sword* getSword();
    void setSword(Sword* sword);
    Shield* getShield();
    void setShield(Shield* shield);
    Staff* getStaff();
    void setStaff(Staff* sword);
    string getStats() const;
    void updDamage();
    void updDefence();
};

#endif // MONSTER_H
