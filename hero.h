#ifndef HERO_H
#define HERO_H

#include "livingcreature.h"
#include "potion.h"
#include "inventory.h"
#include "merchant.h"

class Hero : public LivingCreature
{
protected:
    string m_class;
    Inventory* m_inventory;
public:
    Hero(const string &name, const int maxHp, const int golds, const int damage, const int defence, const string &p_class);
    virtual ~Hero();
    string& getClass();
    Inventory* getInventory();
    string addToInventory(Potion *potion);
    string addToInventory(Weapon *weapon);
    string removeFromInventory(Potion *potion);
    string talk() const;
    void drink(Potion *potion);
    void trade(Merchant *merchant, string objectType, int index);
};

#endif // HERO_H
