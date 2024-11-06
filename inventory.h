#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "potion.h"
#include "weapon.h"

class Inventory
{
private:
    size_t m_space;
    vector<Potion*> m_potions;
    vector<Weapon*> m_weapons;
public:
    Inventory();
    size_t getSpace();
    string addSpace();
    vector<Potion*> showPotions();
    string addPotion(Potion* potion);
    string removePotion(Potion* potion);
    vector<Weapon*> showWeapons();
    string addWeapon(Weapon* weapon);
    string removeWeapon(Weapon* weapon);
};

#endif // INVENTORY_H
