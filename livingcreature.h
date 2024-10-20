#ifndef LIVINGCREATURE_H
#define LIVINGCREATURE_H
#include <iostream>

using namespace std;

class LivingCreature
{
protected:
    string m_name;
    int m_hp, m_maxHp;
    int m_golds;
    int m_baseDamage, m_damage;
    int m_baseDefence, m_defence;
public:
    LivingCreature(string name, int maxHp, int golds, int damage, int defence);
    void virtual attack(LivingCreature* target) const;
    void virtual showStats() const = 0;
    void updDamage();
    void updDefence();
    void removeHp(int damage);
    void healHp(int heal);
    bool isAlive();
};

#endif // LIVINGCREATURE_H
