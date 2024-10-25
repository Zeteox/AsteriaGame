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
    LivingCreature(const string &name, const int maxHp, const int golds, const int damage, const int defence);
    string &getName();
    void setHp(int hp);
    int getHp() const;
    void setMaxHp(int maxHp);
    int getMaxHp() const;
    void setGolds(int golds);
    int getGolds() const;
    int getBaseDamage() const;
    int getBaseDefence() const;
    void setDamage(int damage);
    int getDamage() const;
    void setDefence(int defence);
    int getDefence() const;
    void attack(LivingCreature *target) const;
    void virtual showStats() const = 0;
    void virtual updDamage();
    void virtual updDefence();
    void removeHp(int damage);
    void healHp(int heal);
    bool isAlive();
};

#endif // LIVINGCREATURE_H
