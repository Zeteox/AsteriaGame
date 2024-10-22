#ifndef SWORD_H
#define SWORD_H

#include "weapon.h"

class Sword : public Weapon
{
private:
    int m_damage;
public:
    Sword(const string& name, const int price, int damage);
    void setDamage(int newDamage);
    int getDamage() const;
    void showStats() const;
};

#endif // SWORD_H
