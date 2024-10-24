#ifndef INVENTORY_H
#define INVENTORY_H
#include <vector>
#include "potion.h"

class Inventory
{
private:
    size_t m_space;
    vector<Potion*> m_potions;
public:
    Inventory();
    string addPotion(Potion* potion);
    string removePotion(Potion* potion);
    string addSpace();
};

#endif // INVENTORY_H
