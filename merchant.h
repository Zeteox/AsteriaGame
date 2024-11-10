#ifndef MERCHANT_H
#define MERCHANT_H

#include <vector>
#include "potion.h"
#include "sword.h"
#include "staff.h"
#include "shield.h"
#include "randomNumber.h"

class Merchant
{
private:
    vector<Weapon*> m_weaponStock;
    vector<Potion*> m_potionStock;
public:
    Merchant();
    ~Merchant();
    vector<Weapon*> getWeaponStock();
    vector<Potion*> getPotionStock();
    void addPotion(Potion* potion);
    void addWeapon(Weapon* weapon);
    string removeWeapon(Weapon* weapon);
    string removePotion(Potion* potion);

};

#endif // MERCHANT_H
