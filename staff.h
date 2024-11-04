#ifndef STAFF_H
#define STAFF_H
#include "weapon.h"

class Staff : public Weapon
{
private:
    int m_damage;
public:
    Staff(const string& name, const int price, int damage);
    void setDamage(int newDamage);
    int getDamage() const;
    string getStats() const;
};

#endif // STAFF_H
