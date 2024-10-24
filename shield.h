#ifndef SHIELD_H
#define SHIELD_H
#include "weapon.h"

class Shield : public Weapon
{
private:
    int m_defence;
public:
    Shield(const string &name, const int price, int defence);
    void setDefence(int newDefence);
    int getDefence() const;
    void showStats() const;
};

#endif // SHIELD_H
